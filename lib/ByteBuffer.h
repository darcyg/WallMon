#ifndef BYTEBUFFER_H_
#define BYTEBUFFER_H_

class ByteBuffer {
public:
	ByteBuffer(int bufferSize);
	~ByteBuffer();
	void Resize(int newBufferCapacity);
	void Defragment();
	char *GetReadReference();
	char *GetWriteReference();
	int GetCapacity();
	int GetBytesAvailable();
	int GetBytesLeft();
	int GetContinuousBytesLeft();
	void BytesWritten(int size);
	// Assumes that data overwritten is read out in one operation
	void BytesRead(int size);
private:
	char *_buffer;
	int _capacity;
	int _size;
	int _head;
	int _tail;
};


#endif /* BYTEBUFFER_H_ */
