class Solution:
    def InversePairs(self, data):
        if len(data) <= 0:
            return data
        
        start_idx, end_idx = 0, len(data)
        empty_list = [0]*len(data)
    
    def InversePairsCore(self, empty_list, data):
        if len(data) == 1:
            return 0
        
        left_count = self.InversePairsCore(empty_list, data[:len(data)/2])
        right_count = self.InversePairsCore(empty_list, data[len(data)/2:])


