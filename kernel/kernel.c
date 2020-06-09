#define VIDEO_MEMORY 0xb8000

void main()
{
    char* video_memory = (char*) VIDEO_MEMORY;
    *video_memory = 'X';
}