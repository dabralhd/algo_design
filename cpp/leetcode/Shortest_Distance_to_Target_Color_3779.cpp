// https://leetcode.com/explore/challenge/card/june-leetcoding-challenge-2021/605/week-3-june-15th-june-21st/3779/


/*

You are given an array colors, in which there are three colors: 1, 2 and 3.

You are also given some queries. Each query consists of two integers i and c, return the shortest distance between the given index i and the target color c. If there is no solution return -1.

Example 1:

Input: colors = [1,1,2,1,3,2,2,3,3], queries = [[1,3],[2,2],[6,1]]
distance: [3,0,3]
Explanation: 
The nearest 3 from index 1 is at index 4 (3 steps away).
The nearest 2 from index 2 is at index 2 itself (0 steps away).
The nearest 1 from index 6 is at index 3 (3 steps away).

Example 2:

Input: colors = [1,2], queries = [[0,3]]
distance: [-1]
Explanation: There is no 3 in the array.

*/


#include <iostream>
#include <limits>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    int a;
         
    public:
        /*static*/ bool comp0(const vector<int>& lhs, const vector<int>& rhs) {
            return lhs[0] < rhs[0];
        }

        /*static*/ bool comp1(const vector<int>& lhs, const vector<int>& rhs) {
            return lhs[1] < rhs[1];
        }        

        vector<int> shortestDistanceColor(vector<int>& colors, vector<vector<int>>& queries) {
            // <preprocessing>
            vector<vector<int>> queries_ext(queries);
            int id = 0;
            for (auto & x: queries_ext)
                x.push_back(id++);

            sort(queries_ext.begin(), queries_ext.end(), comp0);
            sort(queries.begin(), queries.end(), comp0);
            // <\preprocessing>

            const int num_colors = 3+1;  // add 1, as color numbers srart from 1 and not 0. ignore color number 0.   
            const int num_queries = queries.size();       
            //vector<int> distance(queries.size(), numeric_limits<int>::max());
            vector<int> cur_min_distance_of(num_colors, numeric_limits<int>::max()); 
            vector<int> distance_for_query(queries.size(), numeric_limits<int>::max());
            int qid = 0;

            // forward pass
            for(int idx=0; idx < colors.size(); ++idx) {
                // update min_distance
                for(int col=1; col<num_colors; ++col) 
                    if(cur_min_distance_of[col]!=numeric_limits<int>::max()) ++cur_min_distance_of[col];

                cur_min_distance_of[colors[idx]] = 0;

                while(idx==queries[qid][0]) {                    
                    distance_for_query[qid] = cur_min_distance_of[queries[qid][1]];
                    ++qid;

                    if(qid >= num_queries) break;

                }

                if(qid >= num_queries) break;
            }

            // backward pass
            vector<int> rev_cur_min_distance_of(num_colors, numeric_limits<int>::max());
            qid = queries.size() - 1;

            for(int idx=colors.size()-1; idx >= 0; --idx) {
                // update min_distance
                for(int col=1; col<num_colors; ++col) 
                    if(rev_cur_min_distance_of[col]!=numeric_limits<int>::max()) ++rev_cur_min_distance_of[col];

                rev_cur_min_distance_of[colors[idx]] = 0;

                while(idx==queries[qid][0]) {                    
                    if(distance_for_query[qid] > rev_cur_min_distance_of[queries[qid][1]]) 
                        distance_for_query[qid] = rev_cur_min_distance_of[queries[qid][1]];

                    --qid;

                    if(qid < 0) break;
                }

                if(qid < 0) break;
            }

            for (int qid=0; qid < distance_for_query.size(); ++qid)  
                if(distance_for_query[qid] == numeric_limits<int>::max()) 
                    distance_for_query[qid] = -1; 

            // <postprocessing>
            vector<vector<int>> output;

            for(auto i=0; i<distance_for_query.size(); ++i) {
                vector<int> temp(2);
                temp[0] = distance_for_query[i];
                temp[1] = queries_ext[i][2];
                output.push_back(temp);
            }

            sort(output.begin(), output.end(), comp1);

            for(auto i=0; i<distance_for_query.size(); ++i) {
                distance_for_query[i] = output[i][0];
            }            

            // <\postprocessing>       

            return distance_for_query;
        }            
};

int test1() {
    cout << "test 1>>>>" << endl;
    Solution s;
    vector<int> color {1,1,2,1,3,2,2,3,3};
    vector<vector<int>> queries {{1,3},{2,2},{6,1}};
    // expected answers: 3, 0, 3


    vector<int> distance = s.shortestDistanceColor(color, queries);

    for(auto x:distance) {
        cout << x << " " ;
    }
    cout << endl;
    cout << "test 1" << endl << endl;
    return 0; 
}

int test2() {   // colors = [1,2], queries = [[0,3]]  => expected output: -1
    cout << "test 2>>>>" << endl;
    Solution s;
    vector<int> color {1,2};
    vector<vector<int>> queries {{0,3}};
    // expected answers: -1


    vector<int> distance = s.shortestDistanceColor(color, queries);

    for(auto x:distance) {
        cout << x << endl;
    }
    cout << "test 2" << endl << endl;

    return 0; 
}

int test3() {   
    cout << "test 3>>>>" << endl;

     // colors = [2,1,2,2,1], queries = [[1,1],[4,3],[1,3],[4,2],[2,1]]  => expected output: 0, 
    Solution s;
    vector<int> color {2,1,2,2,1};
    vector<vector<int>> queries {{1,1},{4,3},{1,3},{4,2},{2,1}};
    // expected answers: -1

    vector<int> distance = s.shortestDistanceColor(color, queries);

    for(auto x:distance) {
        cout << x << endl;
    }
    cout << "test 3" << endl << endl;    
    return 0; 
}

int test4() {   
    cout << "test 4>>>>" << endl;

     // colors = [1,1,2,1,3,2,2,3,3], queries = [[1,3],[2,2],[6,1]]  => expected output: 3,0,3 
    Solution s;
    vector<int> color {1,1,2,1,3,2,2,3,3};
    vector<vector<int>> queries {{1,3},{2,2},{6,1}};
    // expected answers: -1

    vector<int> distance = s.shortestDistanceColor(color, queries);

    for(auto x:distance) {
        cout << x << endl;
    }
    cout << "test 4" << endl << endl;    
    return 0; 
}



int main() {
    // t1 -> colors = [1, 1, 2, 1, 3, 2, 2, 3, 3], queries = [[1,3],[2,2],[6,1]]
    // forward_pass => inf, 0, 3
    // backward_pass => 3 0 inf
    //cout << __cplusplus << endl;

    //test1();    
    //test2();
    //test3();
    test4();

    return 0;    
}