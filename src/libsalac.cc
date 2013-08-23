#include "libsalac.h"
#include <stdio.h>
#include "lib/alac/codec/ALACEncoder.h"
#include "lib/alac/codec/ALACBitUtilities.h"

static int kBlockSize = 16;
static int kFramesPerPacket = 352;

static ALACEncoder* encoder = new ALACEncoder();

void FillInputAudioFormat(AudioFormatDescription *format) {
    format->mFormatID = kALACFormatLinearPCM;
    format->mSampleRate = 44100;
    format->mFormatFlags = 12;

    format->mBytesPerPacket = 4;
    format->mBytesPerFrame = 4;
    format->mBitsPerChannel = 16;
    format->mChannelsPerFrame = 2;
    format->mFramesPerPacket = 1;

    format->mReserved = 0;
}

void FillOutputAudioFormat(AudioFormatDescription *format) {
    format->mFormatID = kALACFormatAppleLossless;
    format->mSampleRate = 44100;
    format->mFormatFlags = 1;

    format->mBytesPerPacket = 0;
    format->mBytesPerFrame = 0;
    format->mBitsPerChannel = 0;
    format->mChannelsPerFrame = 2;
    format->mFramesPerPacket = kFramesPerPacket;

    format->mReserved = 0;
}

/* Initialize the encoder */
void init_encoder(void) {

    AudioFormatDescription inputFormat, outputFormat;
    FillOutputAudioFormat(&outputFormat);

    encoder->SetFrameSize(kFramesPerPacket);
    encoder->InitializeEncoder(outputFormat);
    
}

/* Delete the encoder object, call desctructor */
void delete_encoder(void) {
    delete(encoder);
}

int encode_alac(unsigned char* pcm_data, int pcm_size, unsigned char* alac_data, int alac_size) {

    AudioFormatDescription inputFormat, outputFormat;
    FillInputAudioFormat(&inputFormat);
    FillOutputAudioFormat(&outputFormat);

    alac_size = pcm_size;
    encoder->Encode(inputFormat, outputFormat, pcm_data, alac_data, &alac_size);
//    printf("Encoded %d PCM characters to %d ALAC characters", pcm_size, alac_size);    
    
    return alac_size;
}
