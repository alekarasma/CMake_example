#include<stdio.h>
#include<string.h>
#include"kcapi.h"

uint8_t plain_data[8] = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07};
uint8_t encrypted_data[8] = {0x00};
uint8_t decrypted_data[8] = {0x00};
uint8_t key[8] = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07};

int main(void)
{
    struct kcapi_handle *handle;
    char *ciphername = "cbc(des)"; 
    int ret;

    printf("This is a Crypto test project\n");
    ret = kcapi_cipher_init(&handle,  ciphername, 0);
    if(ret < 0)
    {
        printf("Cipher initialization failed. ret = %d\n", ret);
        return -1;
    }

    printf("Cipher initialised \n");
    ret = kcapi_cipher_setkey(handle, key, sizeof(key));
    if(ret)
    {
        printf("Cipher set key failed. ret = %d\n",ret);
        return -1;
    }

    printf("Cipher set key done \n");

    ret= kcapi_cipher_encrypt(handle, plain_data, sizeof(plain_data), 0, encrypted_data, sizeof(encrypted_data), KCAPI_ACCESS_SENDMSG);
    if(ret < 0)
    {
        printf("Cipher encrypt operation failed. ret = %d\n", ret);
        return -1;
    }

    printf("Encrypted output = \n");
    for(uint8_t i=0; i < 8; i++)
        printf("0x%x\t", encrypted_data[i]);
    
    printf("\n");

    ret = kcapi_cipher_decrypt(handle, encrypted_data, sizeof(encrypted_data), 0, decrypted_data, sizeof(decrypted_data), KCAPI_ACCESS_SENDMSG);
    if(ret < 0)
    {
        printf("Cipher decrypt operation failed. ret = %d\n", ret);
        return -1;
    }

    printf("Decrypted output = \n");
    for(uint8_t i=0; i < 8; i++)
        printf("0x%x\t", decrypted_data[i]);
    
    printf("\n");

    ret = memcmp(plain_data, decrypted_data, sizeof(plain_data));
    if(ret != 0)
    {
        printf("Cipher operation failed. ret = %d\n", ret);
    }

    printf("decrypted_data is equal to plain_data\n");
    return 0;
}