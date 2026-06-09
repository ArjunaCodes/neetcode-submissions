class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> courses(numCourses, vector<int>());
        vector<int> indeg(numCourses, 0);
        for(int i=0; i<prerequisites.size(); ++i) {
            indeg[prerequisites[i][1]]++;
            courses[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        queue<int> execute;
        for(int i=0; i < numCourses; ++i) {
            if(indeg[i] == 0) {
                execute.push(i);
            }
        }
        vector<int> result(numCourses);
        int finish = 0;
        while(not execute.empty()) {
            int node = execute.front();
            execute.pop();
            result[numCourses - finish - 1] = node;
            finish++;
            for(auto pre: courses[node]) {
                indeg[pre]--;
                if(indeg[pre] == 0) {
                    execute.push(pre);
                }
            }
        }
        if(finish != numCourses) {
            return {};
        }
        return result;
    }

};
