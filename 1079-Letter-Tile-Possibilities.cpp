class Solution {
public:
    int numTilePossibilities(string tiles) {
        set<string> str;
        sort(tiles.begin(), tiles.end()); // Sort to handle duplicates
        vector<bool>used(tiles.size(),false);
        dfs(tiles, 0, "", str, used);
        return str.size() - 1; // Subtract empty string
    }

    void dfs(string& tiles, int i, string formed, set<string>& str, vector<bool>& used) {
        str.insert(formed); // Store the current sequence
        
        for (int j = 0; j < tiles.length(); j++) {
            if (used[j] || (j > 0 && tiles[j] == tiles[j - 1] && !used[j - 1])) 
                continue; // Skip duplicate choices

            used[j] = true;
            dfs(tiles, i + 1, formed + tiles[j], str, used);
            used[j] = false; // Backtrack
        }
    }
};
