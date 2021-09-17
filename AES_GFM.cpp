#include<stdio.h>
#include<stdint.h>
using namespace std;
#define ROTL8(x,shift) ((uint8_t) ((x) << (shift)) | ((x) >> (8 - (shift))))


class AES{
    public:
    
    int gmul(unsigned char a,unsigned char b){
        unsigned char p = 0;
        unsigned char counter;
        unsigned char hi_bit_set;
        for(counter = 0;counter<8;counter++){
            if((b&1)==1){
                p^=a;
            }
            hi_bit_set  = a & 0x80;
            a <<= 1;
            if(hi_bit_set == 0x80){
                a^= 0x1b;
            }
            b >>= 1; 
        }
        return p;
    }
    void initialize_aes_sbox(uint8_t sbox[256]) {
	uint8_t p = 1, q = 1;
	
	/* loop invariant: p * q == 1 in the Galois field */
	do {
		/* multiply p by 3 */
		p = p ^ (p << 1) ^ (p & 0x80 ? 0x1B : 0);

		/* divide q by 3 (equals multiplication by 0xf6) */
		q ^= q << 1;
		q ^= q << 2;
		q ^= q << 4;
		q ^= q & 0x80 ? 0x09 : 0;

		/* compute the affine transformation */
		uint8_t xformed = q ^ ROTL8(q, 1) ^ ROTL8(q, 2) ^ ROTL8(q, 3) ^ ROTL8(q, 4);

		sbox[p] = xformed ^ 0x63;
	} while (p != 1);

	/* 0 is a special case since it has no inverse */
	sbox[0] = 0x63;
}
};
int main(){
    AES aes;
    uint8_t sbox[256];
    aes.initialize_aes_sbox(sbox);
    unsigned char b = 0x1b;
    unsigned char a = 0x01;
    for(int i = 0;i<256;i++){
        a = aes.gmul(a,b);
        printf("0x%02X\n", a);
    }
    int ans = aes.gmul(0x93,0xe5);

}