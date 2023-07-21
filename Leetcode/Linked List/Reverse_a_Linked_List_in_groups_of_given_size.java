// Question asked in  Paytm VMWare Accolite Amazon Microsoft Snapdeal Hike MakeMyTrip Walmart Goldman Sachs Adobe SAP Labs
// How to Reverse a Linked List in groups of given size (using Stack)[GeeksForGeeks POTD - dated 21 July, 2023]

/*node class of the linked list

class Node
{
    int data;
    Node next;
    Node(int key)
    {
        data = key;
        next = null;
    }
}

*/

class Solution
{
    public static Node reverse(Node node, int j)
    {
        //Your code here
        Node first=null,second=node,third=null,fhead=null,temp=null;
        int c=0;
        while(node!=null){
            while(second!=null && c<j){
                third=second.next;
                second.next=first;
                first=second;
                second=third;
                c++;
            }
            if(fhead==null)fhead=first;
            if(temp!=null)temp.next=first;
            temp=node;
            first=null;
            node=second;
            c=0;
        }
        return fhead;
    }
}
