class Solution {
public:
    int calculate(string s) {
        stack<string> st;
        vector<string> vec;
        for(int i=0;i<s.length();)
        {
            if(s[i]==' ')
            {
                i++;
                continue;
            }
            string t = "";
            while(i<s.length() && isdigit(s[i]))
            {
                t += s[i];
                i++;
            }
            if(!t.empty())
            {
                st.push(t);
            }
            if(i<s.length() && (s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/'))
            {
                st.push(string(1,s[i]));
                i++;
            }
        }
        while(!st.empty())
        {
            vec.push_back(st.top());
            st.pop();
        }
        reverse(vec.begin(),vec.end());
        stack<string> temp;
        for(int i=0;i<vec.size();)
        {
            if(vec[i]=="*"||vec[i]=="/")
            {
                int num1 = stoi(temp.top());
                temp.pop();
                int num2 = stoi(vec[i+1]);
                int res = (vec[i]=="*")?(num1*num2):(num1/num2);
                temp.push(to_string(res));
                i+=2;
            }
            else
            {
                temp.push(vec[i]);
                i++;
            }
        }
        vector<string> newVec;
        while(!temp.empty())
        {
            newVec.push_back(temp.top());
            temp.pop();
        }
        reverse(newVec.begin(),newVec.end());
        int result = stoi(newVec[0]);
        for(int i=1;i<newVec.size();i+=2)
        {
            string op = newVec[i];
            int num = stoi(newVec[i+1]);
            if(op=="+") result += num;
            else if(op == "-") result -= num;
        }
        return result;
    }
};
