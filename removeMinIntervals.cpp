//Remove minimum intervals to make other intervals non-intersecting

//Given a list of start times and end times, find the minimum count of intervals
//that can be removed so that no intervals are intersecting each other

//Approach: We use two pointers on left and right intervals and move them
//          according to the matching case below. Might need more scenarios for edge cases

/*
Cases:
    Case 1: Left interval ends before right interval begins
        Sol: No intersection. Move pointers to the next interval pair
    Case 2: Left interval ends within the right interval
        Sol: Intersection. Increase count. Move right pointer to next interval
    Case 3: Left interval ends after right interval end (full consumes right interval)
        Sol: Intersection. Increase count. Move both right and left pointers to their next elements
*/

#include<bits/stdc++.h>
using namespace std;

class Interval{
    public:
        int start;
        int end;
        Interval(int start, int end):start{start},end{end}{}
};

bool comparator(Interval e1, Interval e2){
    return e1.start<e2.start;
}

int getRemovedIntervalsCount(vector<Interval>& intervals){
    int count = 0;
    int n = intervals.size();
    sort(intervals.begin(),intervals.end(),comparator); //sort intervals in asc order of start time
    int left = 0, right = 1; //left and right pointers
    while(right<n){
        if(intervals[left].end <= intervals[right].start){ //case 1
            left=right;
            right++;
        }else if(intervals[left].end <= intervals[right].end){ //case 2
            count++;
            right++;
        }else if(intervals[left].end > intervals[right].end){ //case 3
            count++;
            left = right;
            right++;
        }
    }
    return count;
}

int main(){
    vector<Interval> intervals = {{1,3},{2,6},{3,5},{5,10}};
    cout<<"Given intervals:\n";
    for(auto e:intervals){
        cout<<e.start<<" "<<e.end<<"\n";
    }
    cout<<"Minimum number of intervals to be removed: "<<getRemovedIntervalsCount(intervals);
}