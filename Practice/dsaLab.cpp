#include <iostream>
using namespace std;

struct stack

int main()
{
    return 0;
}
// A Node One 
class Node
{
    int data;
    Node next;

    public Node(int data) {
        this.data = data;
        this.next = next;
        
    }
    
}
// This is the Operations 
class LL{
    Node head;
    // For the Insertion
    public void insert(int data) {
        Node newNode = new Node(data);
        if(head == null) {
            // if there is Nothing Please let me Fix the head to the New Node
            
            head = newNode;
        }
        else {
            newNode.next=head;
            head = newNode;
        }
    }
    // For the Insertion at the End 
public void insertionatend(int data) {
        Node newNode = new Node(data);
        if(head ==null) {
            head = newNode;
            
        }
        
        // Remember We Always Implement the At the End But we use here the Temp var which will Move to the Each of the Node
        
        else {
            Node temp = head;
            while(temp.next != null) {
                temp = temp.next;
                
            }
            
            
            temp.next = newNode;
            
        }
        
        // This is for the At the End 
  
        
}

    public void InsertAtPos(int pos, int data )
    {
// Here if the Pos is the 1 then Insert At the First
        Node newNode = new Node(data);
        Node temp = head;
        if(pos==1)
        {
            newNode.next = head;
            head = newNode;
        }
        else {
            if(pos==0)
            {
                System.out.println("You cannot Enter At the Poaition 0");
                
            }
            else {
                for(int i=0; i<pos-1; i++)
                {
                    temp = temp.next;
                    
                }
                //When a Node will be Inserted This Line will Shift out all of the Other Elments Remaining in the nodes
                
                newNode.next = temp.next;
            }
        }
        
    }
    
    //  For the Dsiplaing 
    public void display() {
        Node temp = head;
        while(temp != null) {
            System.out.print(temp.data+" ");
            temp = temp.next;
            
        }
        System.out.println();
        
    }
}


// These Are the Main classes 
public class Main {
    public static void main(String[] args) {
        LL ll = new LL();
        ll.insert(1);   
        ll.insert(2);
        ll.insert(3);
        ll.insertionatend(23);
        ll.display();
        
    }
}