#include "_2_AddTwoNumbers.h"

ListNode* _2_AddTwoNumbers::MyaddTwoNumbers(ListNode* l1, ListNode* l2)
{
    ListNode* ret = new ListNode();
    stack<long> a, b;
    long x = 0, y = 0, sum = 0;

    for (ListNode* t = l1; t != nullptr; t = t->next) {
        a.push(t->val);

    }
    for (ListNode* t = l2; t != nullptr; t = t->next) {
        b.push(t->val);
    }
    while (!a.empty())
    {
        x = a.top() + x * 10;
        a.pop();
    }
    while (!b.empty())
    {
        y = b.top() + y * 10;
        b.pop();
    }
    sum = x + y;
    string str = to_string(sum);
    cout << "sum: " << str << endl;
    cout << str.size() << endl;
    ListNode* flag = ret;
    for (int i = 0; i < str.size(); i++)
    {

        cout << "第" << i << "次" << endl;
        int temp = (int)str[str.size() - 1 - i] - '0';
        cout << temp << endl;
        flag->val = temp;
        //如果是最后一次就不用再添加节点，否则就添加为后面增加节点做准备
        if ((i + 1) != str.size()) {
            ListNode* m = new ListNode();
            flag->next = m;
            flag = flag->next;
        }
    }

    cout << ret->val << endl;
    return ret;
}

ListNode* _2_AddTwoNumbers::MyaddTwoNumbers2(ListNode* l1, ListNode* l2)
{
    ListNode* ret = new ListNode();
    bool flag = false;
    int sum = 0;
    ListNode* end = ret;
    ListNode* num1 = l1;
    ListNode* num2 = l2;

    while ((num1 != nullptr) && (num2 != nullptr))
    {
        if (flag)
        {
            sum = num1->val + num2->val + 1;
        }
        else
        {
            sum = num1->val + num2->val;
        }
        end->val = (sum % 10);
        cout << "sum" << "   " << sum << "   " << num1->val << "   " << num2->val << "   " << endl;
        cout << end->val << endl;

        ListNode* newNode = new ListNode();
        end->next = newNode;
        end = end->next;

        if (sum > 9)
        {
            flag = true;
        }
        else
        {
            flag = false;
        }

        num1 = num1->next;
        num2 = num2->next;
    }

    while (num1 != nullptr) {

        if (flag)
        {
            sum = num1->val + 1;
        }
        else
        {
            sum = num1->val;
        }
        end->val = (sum % 10);
        if (sum > 9)
        {
            flag = true;
        }
        else
        {
            flag = false;
        }

        ListNode* newNode = new ListNode();
        end->next = newNode;
        end = end->next;
        num1 = num1->next;
    }
    while (num2 != nullptr) {

        if (flag)
        {
            sum = num2->val + 1;
        }
        else
        {
            sum = num2->val;
        }
        cout << "sum" << sum << endl;
        end->val = (sum % 10);
        if (sum > 9)
        {
            flag = true;
        }
        else
        {
            flag = false;
        }

        ListNode* newNode = new ListNode();
        end->next = newNode;
        end = end->next;
        num2 = num2->next;
    }
    if (flag)
    {
        end->val = 1;
        ListNode* newNode = new ListNode();
        end->next = newNode;
        end = end->next;
    }

    for (ListNode* temp = ret; temp != nullptr; temp = temp->next)
    {
        if (temp->next->next == nullptr)
        {
            temp->next = nullptr;
        }
    }
    return ret;
}

ListNode* _2_AddTwoNumbers::addTwoNumbers(ListNode* l1, ListNode* l2)
{
    ListNode* head = nullptr, * tail = nullptr;
    int carry = 0;  //表示两个节点的值相加之后的进位数
    while (l1 || l2) {
        int n1 = l1 ? l1->val : 0;  //如果l1为真（这个节点不为null），那么就取出这个值，否则这个值为0
        int n2 = l2 ? l2->val : 0;
        int sum = n1 + n2 + carry;
        if (!head) {    //留下头部节点返回
            head = tail = new ListNode(sum % 10);
        }
        else {      //尾节点会一直用来操作下面的数
            tail->next = new ListNode(sum % 10);
            tail = tail->next;
        }
        carry = sum / 10;   //取得进位的数。
        if (l1) {
            l1 = l1->next;
        }
        if (l2) {
            l2 = l2->next;
        }
    }
    if (carry > 0) {        //所有节点加完，发现还有进位，那就再加一个节点，这个节点值只能为1
        tail->next = new ListNode(carry);
    }
    return head;
}

void _2_AddTwoNumbers::testDemo()
{
    /*ListNode* n1 = new ListNode(2);
    ListNode* n2 = new ListNode(4);
    ListNode* n3 = new ListNode(9);
    n1->next = n2;
    n2->next = n3;

    ListNode* m1 = new ListNode(5);
    ListNode* m2 = new ListNode(6);
    ListNode* m3 = new ListNode(4);
    ListNode* m4 = new ListNode(9);
    m1->next = m2;
    m2->next = m3;
    m3->next = m4;*/

    //ListNode* n1 = new ListNode(2);
    //ListNode* n2 = new ListNode(4);
    //ListNode* n3 = new ListNode(9);
    //n1->next = n2;
    //n2->next = n3;

    //ListNode* m1 = new ListNode(5);
    //ListNode* m2 = new ListNode(6);
    //ListNode* m3 = new ListNode(4);
    //m1->next = m2;
    //m2->next = m3;

    ListNode* n1 = new ListNode(5);
    ListNode* n2 = new ListNode(6);
    n1->next = n2;

    ListNode* m1 = new ListNode(5);
    ListNode* m2 = new ListNode(4);
    ListNode* m3 = new ListNode(9);
    m1->next = m2;
    m2->next = m3;

    ListNode* sum = addTwoNumbers(n1, m1);

    cout << endl;
    cout << "2. 两数相加" << endl;
    cout << "给你两个非空的链表，表示两个非负的整数。它们每位数字都是按照逆序的方式存储的，并且每个节点只能存储一位数字。" << endl;
    cout << "请你将两个数相加，并以相同形式返回一个表示和的链表。" << endl;
    cout << "你可以假设除了数字 0 之外，这两个数都不会以 0 开头。" << endl;
    cout << "例如：65+945" << endl;
    cout << "输出链表是：" << endl;
    int ans = 0, n = 0;
    while (sum != nullptr)
    {
        ans = ans + sum->val * pow(10, n++);
        cout << sum->val << " ";
        sum = sum->next;
    }
    cout << endl << "答案是：" << ans << endl;

}
