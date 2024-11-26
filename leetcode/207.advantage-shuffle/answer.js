export default function advantageCount(nums1, nums2) {
    const nums2Map = getSortedMap(nums2)
    nums1.sort((a, b) => b - a)
    const res = new Array(nums2.length)
    let n1i = 0
    let n1End = nums1.length

    for (const [n2v, n2p] of nums2Map) {
        if (n2v >= nums1[n1i]) {
            res[n2p] = nums1[--n1End];
        } else {
            res[n2p] = nums1[n1i++];
        }
    }
    return res
};
function getSortedMap(n) {
    return n.map((v, i)=> [v, i]).sort((a, b) => b[0] - a[0])
}