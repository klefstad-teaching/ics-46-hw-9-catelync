# include "ladder.h"

// error
void error(string word1, string word2, string msg)
{
    cerr << "Error: " << msg << " (" << word1 <<< ", " << word2 << ")" << endl;
}

// is adj
bool edit_distance_within(const std::string& str1, const std::string& str2, int d)
{
    int len1 = word1.length();
    int len2 = word2.length();
    if (abs(len1 - len2) > d)
    {
        return false;
    }
    int diff_count = 0;
    int i = 0;
    int j = 0;
    while (i < len1 && j < len2)
    {
        if (str1[i] != str2[j])
        {
            if (++diff_count > d)
            {
                return false;
            }
            if (len1 > len2)
            {
                i++;
            }
            else if (len1 < len2)
            {
                j++;
            }
            else
            {
                i++;
                j++;
            }
        }
        else 
        {
            i++;
            j++;
        }
    }
    return true; 
}

bool is_adjacent(const string& word1, const string& word2)
{
    return edit_distance_within(word1, word2, 1);
}

// gen word ladder
vector<string> generate_word_ladder(const string& begin_word, const string& end_word, const set<string>& word_list)
{
    queue<vector<string>> ladders;
    ladders.push({begin_word});
    set<string> visited;
    visited.insert(begin_word);
    while (!ladders.empty())
    {
        int level_size = ladders.size();
        set<string> level_visited;
        while (level_size--)
        {
            vector<string> path = ladders.front(); ladders.pop();
            string last_word = path.back();
            if (last_word == end_word)
            {
                return path;
            }
            for (const string& word : word_list)
            {
                if (is_adjacent(last_word, word) && !visited.count(word))
                {
                    vector<string> new_path = path;
                    new_path.push_back(word);
                    ladders.push(new_path);
                    level_visited.insert(word);
                }
            }
        }
        visited.insert(level_visited.begin(), level_visited.end());
    }
    return {};
}

// load words
void load_words(set<string>& word_list, const string& file_name)
{
    ifstream file(file_name);
    if (!file)
    {
        cerr << "Error: Unable to open word file." << endl;
        return; 
    }
    string word;
    while (file >> word)
    {
        word_list.insert(word);
    }
    file.close();
}

// print word ladder
void print_word_ladder(const vector<string>& ladder)
{
    if (ladder.empty())
    {
        cout << "No word ladder found." << endl;
        return;
    }
    for (size_t i = 0; i < ladder.size(); ++i)
    {
        cout << ladder[i];
        if (i < ladder.size() - 1)
        {
            cout << " -> ";
        }
    }
    cout << endl; 
}