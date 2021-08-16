#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

class SinglyLinkedListNode {
    public:
        int data;
        SinglyLinkedListNode *next;

        SinglyLinkedListNode(int node_data) {
            this->data = node_data;
            this->next = nullptr;
        }
};

class SinglyLinkedList {
    public:
        SinglyLinkedListNode *head;
        SinglyLinkedListNode *tail;

        SinglyLinkedList() {
            this->head = nullptr;
            this->tail = nullptr;
        }

        void insert_node(int node_data) {
            SinglyLinkedListNode* node = new SinglyLinkedListNode(node_data);

            if (!this->head) {
                this->head = node;
            } else {
                this->tail->next = node;
            }

            this->tail = node;
        }
};

void print_singly_linked_list(SinglyLinkedListNode* node, string sep, ofstream& fout) {
    while (node) {
        fout << node->data;

        node = node->next;

        if (node) {
            fout << sep;
        }
    }
}

/*
 * Complete the 'get_final_processes_list' function below.
 *
 * The function is expected to return an INTEGER_SINGLY_LINKED_LIST.
 * The function accepts following parameters:
 *  1. INTEGER_SINGLY_LINKED_LIST processes_list
 *  2. INTEGER processor_count
 */

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
//->this function
SinglyLinkedListNode* get_final_processes_list(SinglyLinkedListNode* pl, int pc) {
    // Write your function here. Do not change anything elsewhere
    vector<SinglyLinkedListNode> list;
    SinglyLinkedListNode* temp=pl;
    while(temp->next!=nullptr)
    {
        list.push_back(*temp);
        temp=temp->next;
    }
    return nullptr;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string processor_count_temp;
    getline(cin, processor_count_temp);

    int processor_count = stoi(ltrim(rtrim(processor_count_temp)));

    SinglyLinkedList* process_list = new SinglyLinkedList();

    string process_list_count_temp;
    getline(cin, process_list_count_temp);

    int process_list_count = stoi(ltrim(rtrim(process_list_count_temp)));

    for (int i = 0; i < process_list_count; i++) {
        string process_list_item_temp;
        getline(cin, process_list_item_temp);

        int process_list_item = stoi(ltrim(rtrim(process_list_item_temp)));

        process_list->insert_node(process_list_item);
    }

    SinglyLinkedListNode* final_processes_list = get_final_processes_list(process_list->head, processor_count);

    print_singly_linked_list(final_processes_list, " ", fout);
    fout << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
