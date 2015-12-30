#include <stdio.h>
#include <string.h>
#include <openssl/md5.h>

int main(void)
{
	char key[] = "yzbqklnj";
	char buf[64];
	unsigned char out[MD5_DIGEST_LENGTH];
	int i, k = 0;
	for (i = 1; i < 10000000; i++) {
		MD5_CTX c;
		sprintf(buf, "%s%d", key, i);
		MD5_Init(&c);
		MD5_Update(&c, buf, strlen(buf));
		MD5_Final(out, &c);
		if (out[0] == 0 && out[1] == 0 && out[2] == 0) {
			printf("%d\n", i);
			break;
		}
		if (k == 0 && out[0] == 0 && out[1] == 0 && (out[2] & 0xf0) == 0) {
			printf("%d\n", i);
			k = 1;
		}
	}
	return 0;
}
