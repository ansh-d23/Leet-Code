class Solution {

    string a = "IPv4";
    string b = "IPv6";
    string c = "Neither";

public:
    bool Isipv4(string temp){ 

        if(temp.empty() || temp.length() > 3) return false;

        if(temp[0]=='0' && temp.length()>1) return false;

        for(char ch : temp){
            if(!isdigit(ch)) return false;
        }

        int val;
        try {
            val = stoi(temp);
        } catch (exception& e) {
            return false; 
        }

        if(val >= 0 && val <= 255) return true;
        return false;

    }

    bool Isipv6(string temp){

        vector<int> hash(256,0);
        hash['A']++; hash['B']++; hash['C']++; hash['D']++; hash['E']++; hash['F']++;
        hash['a']++; hash['b']++; hash['c']++; hash['d']++; hash['e']++; hash['f']++;
        hash['0']++; hash['1']++; hash['2']++; hash['3']++; hash['4']++; hash['5']++;
        hash['6']++; hash['7']++; hash['8']++; hash['9']++;

        if(temp.empty() || temp.length() > 4) return false;


        for(int i=0;i<temp.length();i++){
            if(hash[temp[i]]==0) return false;
        } 

        return true;

    }

    string validIPAddress(string ip) {

        int ipv4 = 0;
        int ipv6 = 0;
        int divider=0;

        string temp;

        for(int i=0;i<ip.length();i++){

            if(ip[i]=='.' || ip[i]==':'){

                divider++;

                if(Isipv4(temp)) ipv4++;
                if(Isipv6(temp)) ipv6++;

                temp="";
            }else{
                temp+=ip[i];
            }
        }

        if(Isipv4(temp)) ipv4++;
        if(Isipv6(temp)) ipv6++;

        if(divider==3 && ipv4==4) return a;
        if(divider==7 && ipv6==8) return b;
        return c;
        
    }
};