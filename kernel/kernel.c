#define VIDEO_MEMORY 0xb8000
void hello()
{
    
}
void main()
{
    char* video_memory = (char*) VIDEO_MEMORY;
    char* msg = "Hello! This is the kernel!";

    while(*msg != 0)
    {
        *video_memory = *msg;
        video_memory += 2;
        msg++;
    }
}
