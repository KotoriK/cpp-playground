
// Definition for singly-linked list.
class ListNode {
    val: number
    next: ListNode | null
    constructor(val?: number, next?: ListNode | null) {
        this.val = (val === undefined ? 0 : val)
        this.next = (next === undefined ? null : next)
    }
}


function addTwoNumbers(l1: ListNode | null, l2: ListNode | null): ListNode | null {
    let result: ListNode | null = null
    let resultCurrNode: ListNode | null = result
    let carry = false // 进位标志
    while (l1 || l2) {
        let sum = (l1 ? l1.val : 0) + (l2 ? l2.val : 0) + (carry ? 1 : 0)
        if (sum >= 10) {
            carry = true
            sum -= 10
        } else {
            carry = false
        }
        const nextNode = new ListNode(sum)

        if (resultCurrNode) {
            resultCurrNode.next = nextNode
        } else {
            result = nextNode
        }
        resultCurrNode = nextNode

        l1 = l1 && l1.next
        l2 = l2 && l2.next
    }
    if (carry) {
        resultCurrNode!.next = new ListNode(1)
    }
    return result
};

// case 1
const case1_a = new ListNode(2, new ListNode(4, new ListNode(3)))
const case1_b = new ListNode(5, new ListNode(6, new ListNode(4)))
console.log(addTwoNumbers(case1_a, case1_b))