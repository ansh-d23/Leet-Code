class Solution {
public:
    int maxDiff(int num) {

        string str1 = to_string(num);
        string str2 = to_string(num);

        int n = str1.length();

        char set='9';
        bool flag = true;

        for(int i=0;i<n;i++){
            if(flag && str1[i]!='9'){
                set = str1[i];
                flag=false;
            }

            if(str1[i]==set) str1[i]='9';
        }

        set='0';
        flag = false;

        //70075 --> 7==1 i==0 !=1 then set=str & val1;
        //1005 --> 5==0 i>0 && str!=0 then set==str & val=0;
        int i=0;
        while(str2[i]=='0' || str2[i]=='1') i++;

        if(i==0){
            set = str2[i];
            flag=true;
        }else{
            set=str2[i];
        }

        for(int j=0;j<n;j++){
            if(str2[j]==set && flag){
                str2[j]='1';
            }
            if(str2[j]==set && !flag){
                str2[j]='0';
            }
        }

        int val1 = stoi(str1);
        int val2 = stoi(str2);

        return val1-val2;
    }
};