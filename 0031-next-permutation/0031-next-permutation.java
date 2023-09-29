class Solution {
    public void nextPermutation(int[] nums) {
        Integer pos = nums.length - 2;
        PriorityQueue<Integer> maxHeap = new PriorityQueue<>(Comparator.reverseOrder());
        maxHeap.add(nums[nums.length - 1]);
        while(pos >= 0) {
            if (nums[pos] < maxHeap.peek()) {
                int top = maxHeap.peek(), temp = nums.length - 1;
                maxHeap.poll();
                while(maxHeap.size() > 0 && maxHeap.peek() > nums[pos]) {
                    nums[temp--] = top;
                    top = maxHeap.poll();
                }
                nums[temp--] = nums[pos];
                nums[pos] = top;
                while(maxHeap.size() > 0) {
                    nums[temp--] = maxHeap.poll();
                }
                return;
            }
            maxHeap.add(nums[pos]);
            --pos;
        }
        Arrays.sort(nums);
    }
}