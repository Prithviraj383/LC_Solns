class Solution {
public:
    int maxProduct(int n) {
        string temp;
        while(n){
            int rem = n%10;
            temp.push_back(rem+'0');
            n/=10;
        }

        sort(temp.rbegin(), temp.rend());
        cout << temp << endl;
        return (temp[0] - '0')*(temp[1] - '0');
    }
};