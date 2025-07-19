class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());
        vector<string> ans;

        if (folder.empty()) return ans;

        ans.push_back(folder[0]);

        for (int i = 1; i < folder.size(); i++) {
            string current_folder = folder[i];
            string last_root_folder = ans.back();

            if (current_folder.length() > last_root_folder.length() &&
                current_folder.rfind(last_root_folder, 0) == 0 && 
                current_folder[last_root_folder.length()] == '/') {
                // This means current_folder is a subfolder of last_root_folder.
            } else {
                ans.push_back(current_folder);
            }
        }
        return ans;
    }
};