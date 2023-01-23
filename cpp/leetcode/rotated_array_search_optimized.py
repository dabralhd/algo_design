class Solution:    
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        def lowerIndex(nums: List[int], target: int) -> int:
            l, h = 0, len(nums) - 1

            while l <= h:
                m = (l + h) // 2
                if target < nums[m]:
                    h = m - 1
                elif target > nums[m]:
                    l = m + 1
                elif m>0 and nums[m] == nums[m-1]:
                    h = m -1
                else:
                    return m
            return -1

        def upperIndex(nums: List[int], target: int) -> int:
            l, h = 0, len(nums) - 1

            while l <= h:
                m = (l + h) // 2
                if target < nums[m]:
                    h = m - 1
                elif target > nums[m]:
                    l = m + 1
                elif m<len(nums)-1 and nums[m] == nums[m+1]:
                    l = m + 1
                else:
                    return m
            return -1

        return [lowerIndex(nums, target), upperIndex(nums, target)]





        
