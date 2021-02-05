﻿#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

class Long_number {
private:
    vector <int> v;
    bool is_pos = true;
    const int D = 1000000; // система счисления
    const int C = 6; // кол-во разрядов
    void clean_zeros() {
        while (v[v.size() - 1] == 0) {
            v.pop_back();
        }
    }

    int str_to_int(string str) {
        istringstream istr(str);
        int number;
        istr >> number;
        return number;
    }
    // сложение модулей
    Long_number add(Long_number& left, Long_number& right) {
        left.clean_zeros();
        right.clean_zeros();
        Long_number sum;
        vector <int> v_min;
        int s, r = 0;
        if (is_bigger(left, right)) {
            sum.v = left.v;
            v_min = right.v;
        }
        else {
            sum.v = right.v;
            v_min = left.v;
        }
        int i;
        for (i = 0; i < v_min.size(); i++) {
            s = sum.v[i] + v_min[i] + r;
            r = s / D;
            sum.v[i] = s % D;
        }
        for (; i < sum.v.size(); i++) {
            s = sum.v[i] + r;
            r = s / D;
            sum.v[i] = s % D;
        }
        sum.clean_zeros();
        return sum;
    }
    // разность модулей
    Long_number substract(Long_number left, Long_number right) {
        left.clean_zeros();
        right.clean_zeros();
        // немного костылей из-за того что я ленивый
        if (!left.is_pos) {
            left.is_pos = !left.is_pos;
        }
        if (!right.is_pos) {
            right.is_pos = !right.is_pos;
        }
        Long_number def;
        vector <int> v_min;
        int s, r = 0;
        if (is_bigger(left, right)) {
            def.v = left.v;
            v_min = right.v;
        }
        else {
            def.v = right.v;
            v_min = left.v;
        }
        int i;
        for (i = 0; i < v_min.size(); i++) {
            s = def.v[i] - v_min[i] - r;
            if (s < 0) {
                s += D;
                r = 1;
            }
            else {
                r = 0;
            }
            def.v[i] = s % D;
        }
        for (; i < def.v.size(); i++) {
            s = def.v[i] - r;
            if (s < 0) {
                s += D;
                r = 1;
            }
            else {
                r = 0;
            }
            def.v[i] = s % D;
        }
        return def;
    }
public:
    Long_number(string s) {
        if (s[0] == '-') {
            is_pos = false;
            s = s.substr(1, s.size() - 1);
        }
        while (s[0] == '0' && s.size() > 1) {
            s = s.substr(1, s.size() - 1);
        }
        int k = s.size() / C;
        if (s.size() % C != 0) {
            k++;
        }
        v = vector<int>(k, 0);
        int i = s.size() - C;
        int j = 0;
        while (i > 0) {
            string s1 = s.substr(i, C);
            int x = str_to_int(s1);
            v[j] = x;
            j++;
            i -= C;
        }
        string s1 = s.substr(0, i + C);
        int x = str_to_int(s1);
        v[j] = x;
    }
    Long_number() {
        v.push_back(0);
    }
    Long_number& operator= (const Long_number& right) {
        is_pos = right.is_pos;
        v = right.v;
        return *this;
    }
    Long_number operator+(Long_number& right) {
        if (is_pos && right.is_pos) {
            return add(*this, right);
        }
        else if (!is_pos && !right.is_pos) {
            Long_number sum;
            sum = add(*this, right);
            sum.is_pos = false;
            return sum;
        }
        else if (!is_pos && right.is_pos) {
            Long_number sum;
            sum = substract(*this, right);
            if (is_bigger(*this, right)) {
                sum.is_pos = false;
            }
            else {
                sum.is_pos = true;
            }
            return sum;
        }
        else if (is_pos && !right.is_pos) {
            Long_number sum;
            sum = substract(*this, right);
            if (is_bigger(right, *this)) {
                sum.is_pos = false;
            }
            else {
                sum.is_pos = true;
            }
            return sum;
        }
    }
    Long_number operator-(Long_number right) {
        right.is_pos = !is_pos;
        return *this + right;
    }
    string str() {
        string s = "";
        stringstream str;
        if (!is_pos) {
            str << "-";
        }
        int k = v.size() - 1;
        str << v[k];
        for (k -= 1; k >= 0; k--) {
            int M = D / 10;
            int x = v[k];
            while (M > 0) {
                str << x / M;
                x %= M;
                M /= 10;
            }
        }
        str >> s;
        return s;
    }
    bool is_bigger(Long_number& left, Long_number& right) {
        string s_r = left.str();
        string s_l = right.str();
        // левое - положительное, а правое - отрицательное
        if (s_r[0] == '-' && s_l[0] != '-') {
            return true;
        }
        // левое - отрицательное, а правое - положительное
        else if (s_r[0] != '-' && s_l[0] == '-') {
            return false;
        }
        // оба положительные
        else if (s_r[0] != '-' && s_l[0] != '-') {
            if (s_r.size() < s_l.size()) {
                return true;
            }
            else if (s_r.size() > s_l.size()) {
                return false;
            }
            else {
                for (int i = 0; i < s_r.size(); i++) {
                    if (s_l[i] > s_r[i]) {
                        return true;
                    }
                    if (s_l[i] < s_r[i]) {
                        return false;
                    }
                    else {
                        continue;
                    }
                }
                return false;
            }
        }
        //оба отрицательные
        else {
            if (s_r.size() < s_l.size()) {
                return false;
            }
            else if (s_r.size() > s_l.size()) {
                return true;
            }
            else {
                for (int i = 0; i < s_r.size(); i++) {
                    if (s_l[i] > s_r[i]) {
                        return false;
                    }
                    if (s_l[i] < s_r[i]) {
                        return true;
                    }
                    else {
                        continue;
                    }
                }
                return false;
            }
        }
    }
};

int main()
{
    Long_number numb("3216568713546513");
    Long_number numb2("1348649687213241654");
    Long_number numb3;
    numb3 = numb + numb2;
    cout << numb3.is_bigger(numb, numb2);
}
