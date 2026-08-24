class Solution {
public:
    void print_bit_pos(uint32_t value) {
        while(value){
            std::cout<< (value & 1);
            value = value >> 1;
        }
        std::cout<< std::endl;
    }
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans{0};
        for(int i=0; i<32; ++i) {
            bool is_set = (n >> i) & 1;
            if(is_set){
                uint32_t value{1};
                value = value << (31 - i);
                // print_bit_pos(value);
                ans |= value;
            }
        }
        // print_bit_pos(ans);
        return ans;
    }
};