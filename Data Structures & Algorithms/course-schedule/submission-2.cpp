class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> courses(numCourses, vector<int>());
        for(int i=0; i<prerequisites.size(); ++i) {
            courses[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        unordered_set<int> prereq;
        for(int i=0; i<courses.size(); ++i) {
            unordered_set<int> pre;
            if(courses[i].size() and prereq.find(i) == prereq.end()) {
                if(not solve_depends(courses, pre, i)) return false;
            }
            prereq.insert(pre.begin(), pre.end());
        }
        return true;
    }
    bool solve_depends(vector<vector<int>>& courses, unordered_set<int>& prereq, int course) {
        if(courses[course].size() == 0) return true;
        if(prereq.find(course) != prereq.end()) return false;
        prereq.insert(course);
        for(auto req: courses[course]) {
            if(not solve_depends(courses, prereq, req))
                return false;
        }
        prereq.erase(course);
        return true;
    }
};
// 0 -> 1, 2
// 1 -> 3, --
// 2 -> 3,
// 3 -> 4, ----