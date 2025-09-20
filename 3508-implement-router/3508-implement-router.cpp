class Router {
private:
    int MAX_SIZE;  
    unordered_map<string, vector<int>> packetStore;  // key -> {source, dest, timestamp}
    unordered_map<int, vector<int>> destTimestamps;  // destination -> sorted timestamps
    queue<string> que;  // FIFO order

    string makeKey(int source, int destination, int timestamp) {
        return to_string(source) + "#" + to_string(destination) + "#" + to_string(timestamp);
    }

public:
    Router(int memoryLimit) {
        MAX_SIZE = memoryLimit;
    }

    bool addPacket(int source, int destination, int timestamp) {
        string key = makeKey(source, destination, timestamp);

        if (packetStore.find(key) != packetStore.end()) {
            return false;  // duplicate
        }

        if ((int)packetStore.size() >= MAX_SIZE) { 
            forwardPacket(); // remove oldest
        }

        packetStore[key] = {source, destination, timestamp};
        que.push(key);

        // Insert timestamp in sorted order
        auto &vec = destTimestamps[destination];
        auto it = lower_bound(vec.begin(), vec.end(), timestamp);
        vec.insert(it, timestamp);

        return true;
    }

    vector<int> forwardPacket() {
        if (packetStore.empty())
            return {}; 

        string key = que.front(); 
        que.pop();

        vector<int> packet = packetStore[key];
        packetStore.erase(key);

        int dest = packet[1];
        int ts = packet[2];

        // erase timestamp from sorted vector
        auto &vec = destTimestamps[dest];
        auto it = lower_bound(vec.begin(), vec.end(), ts);
        if (it != vec.end() && *it == ts) {
            vec.erase(it);
        }

        return packet;
    }

    int getCount(int destination, int startTime, int endTime) {
        auto it = destTimestamps.find(destination);
        if (it == destTimestamps.end() || it->second.empty())
            return 0;

        auto &vec = it->second;
        int leftIdx = lower_bound(vec.begin(), vec.end(), startTime) - vec.begin();
        int rightIdx = upper_bound(vec.begin(), vec.end(), endTime) - vec.begin();

        return rightIdx - leftIdx;
    }
};
