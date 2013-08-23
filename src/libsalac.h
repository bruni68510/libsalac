#ifdef __cplusplus
extern "C" {
#endif
void init_encoder(void);
void delete_encoder(void);

int encode_alac( unsigned char* pcm_data, int pcm_size, unsigned char* alac_data, int alac_size );

#ifdef __cplusplus
}
#endif
