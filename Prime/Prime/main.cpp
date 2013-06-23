//
//  main.cpp
//  Prime
//
//  Created by USER on 2013/06/23.
//  Copyright (c) 2013年 USER. All rights reserved.
//

#include <iostream>
#include <vector>

#define MAX_NUM "10000"
#define DELI    10

using namespace std;

int main(int argc, const char * argv[])
{
    vector<int> pn;             // 素数格納
    vector<int>::iterator it;
    int fp = 0;                 // １つでも割り切れたら !0
    int len = strlen(MAX_NUM);
    long max_num = atol(MAX_NUM);

    // １から３はセットしておく
    pn.push_back(1);
    pn.push_back(2);
    pn.push_back(3);

    for (int i = 4; i < max_num; i++) {
        fp = 0;
#if _DEBUG
        cout << "--- " << i << " : ";
#endif
        for (it = pn.begin(); it != pn.end(); ++it) {
            if (1 == *it) {
                continue;   // １は必ず割り切れるので計算しない
            }
            if (0 == i % *it) {
                fp++;       // 割り切れた
#if _DEBUG
                cout.width(len);
                cout << *it << ", ";
#endif
            }
        }

        if (0 == fp) {
            // 素数！
#if _DEBUG
            cout << "prime.";
#endif
            pn.push_back(i);
        }
#if _DEBUG
        cout << endl;
#endif
    }

    // 結果出力
    fp = 0;
    for (it = pn.begin(); it != pn.end(); ++it) {
        if (fp != (*it / DELI)) {
            cout << endl;
            fp = *it / DELI;
        }
        cout.width(len);
        cout << *it;
    }

    return 0;
}

