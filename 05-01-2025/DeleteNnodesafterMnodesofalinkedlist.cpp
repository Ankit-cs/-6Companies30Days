/*
Intution :
- Start with the head of the linked list.
- **Skip nodes**: Move the pointer forward \( m \) times.
- **Delete  nodes**: After skipping, delete the next \( n \) nodes by adjusting pointers and freeing memory.
- Reconnect the list: Link the remaining nodes after deletion.
- Continue the process until the end of the list.
- Return the modified head of the linked list.*/
class Solution {
  public:
    Node* linkdelete(Node* head, int n, int m) {
        Node* curr = head;
        Node* t;
        int count;

        while (curr) {
            for (count = 1; count < m && curr != NULL; count++) {
                curr = curr->next;
            }

            if (curr == NULL || curr->next == NULL) {
                return head;
            }

            t = curr->next;
            for (count = 1; count <= n && t != NULL; count++) {
                Node* temp = t;
                t = t->next;
                delete temp;
            }

            curr->next = t;
            curr = t;
        }

        return head;
    }
};

