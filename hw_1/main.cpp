//
//  main.cpp
//  hw_1
//
//  Created by dongho on 2020/03/27.
//  Copyright © 2020 dongho. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
int r=0;
//재귀로 vector 레벨늘려가며 가장많은 노드있는 레벨 저장
void searchMax(vector< vector<int> > level, int max, int a){
    if(a > level.size()-1)
        return;
    if(max < int(level[a].size())){
        max = int(level[a].size());
        r = a;
    }
    searchMax(level, max, a+1);
}

int main(){
    int N;
    cin >> N;
    vector <int> result;
    for(int LN=0; LN<N; LN++){
        vector <vector<int> > level;
        int num;
        cin >> num;
        
        level.push_back(vector<int>());
        int data, lc, rc;
        cin >> data >> lc >> rc;
        
        level.push_back(vector<int>());
        level[1].push_back(data);
        level.push_back(vector<int>());
        if(lc != -1)
            level[2].push_back(lc);
        if(rc != -1)
            level[2].push_back(rc);
        int lev;
        for(int k=1; k<num; k++){
            cin >> data >> lc >> rc;
            //data의 레벨찾기
            bool endflag=0;
            for(int i=1; i<level.size(); i++){
                for(int j=0; j<level[i].size(); j++){
                    if(data == level[i][j]){
                        lev = i;
                        endflag = 1;
                        break;
                    }
                    if(endflag)
                        break;
                }
            }
            //level[data의 레벨+1] pushback lc, rc // but -1은 아예 안함.
            if(lev == level.size()-1)
                level.push_back(vector <int>());
            if(lc != -1)
                level[lev+1].push_back(lc);
            if(rc != -1)
                level[lev+1].push_back(rc);
        }
//
//        for(int i=1; i<=level.size()-1; i++){
//            if(max < int(level[i].size())){
//                max = int(level[i].size());
//                r = i;
//            }
//        }
        searchMax(level, 0, 1);
        result.push_back(r);
        r=0;
    }
    //결과출력
    for(int i=0; i<result.size(); i++)
        cout << result[i] <<endl;
}
