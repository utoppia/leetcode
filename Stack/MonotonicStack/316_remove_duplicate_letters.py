class Solution:
    def removeDuplicateLetters(self, s: str) -> str:
        cnt = {}
        for ch in s:
            if ch in cnt:
                cnt[ch] += 1
            else:
                cnt[ch] = 1
                
        st = []
        # status marks whether a char is in the stack
        # use bit XOR operation
        status = 0 
        for ch in s:
            # if 'ch' was in the stack
            if status ^ (1 << (ord(ch) - ord('a'))) < status:
                cnt[ch] -= 1
                continue

            # if the top of stack is greater than current char
            # and there still has char in the last string
            # pop the top of stack and modify the status
            while st and ord(st[-1]) > ord(ch) and cnt[st[-1]]:
                k = st.pop()
                status ^= (1 << (ord(k) - ord('a')))

            cnt[ch] -= 1
            
            # add current char to the stack
            st.append(ch)
            # update the status
            status ^= (1 << (ord(ch) - ord('a')))

        return ''.join(st)
