#pragma once

/*
cache.hpp

Кеширование записи в файл/чтения из файла
*/
/*
Copyright (c) 2009 Far Group
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions
are met:
1. Redistributions of source code must retain the above copyright
   notice, this list of conditions and the following disclaimer.
2. Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in the
   documentation and/or other materials provided with the distribution.
3. The name of the authors may not be used to endorse or promote products
   derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

class CachedRead
{
public:
	CachedRead(FileSeekDefer& file);
	~CachedRead();

	bool ReadByte(LPBYTE Data);
	DWORD Read(LPVOID Data, DWORD DataSize);
	void Clear();

private:
	FileSeekDefer &file;

	enum
	{
		AlignSize = 0x1000, // must be power of 2
		BufferSize = 0x10000 // must be multiple of AlignSize
	};

	enum BufferDirection
	{
		BufferForward,
		BufferBackward
	};

	LPBYTE Buffer;
	INT64 BufferPtr;
	INT64 BufferEnd;

	INT64 LastReadPtr;

	DWORD ReadAt(INT64 Ptr, LPVOID Data, DWORD DataSize);
	DWORD RefreshReadAt(INT64 Ptr, LPVOID Data, DWORD DataSize, BufferDirection Direction);

	bool DirectTell(INT64 &Ptr);
	bool DirectSeek(INT64 Ptr);
	DWORD DirectReadAt(INT64 Ptr, LPVOID Data, DWORD DataSize);
};


class CachedWrite
{
public:
	CachedWrite(File& file);
	~CachedWrite();
	bool Write(LPCVOID Data, DWORD DataSize);
	bool Flush();

private:
	LPBYTE Buffer;
	File& file;
	enum {BufferSize=0x10000};
	DWORD FreeSize;
	bool Flushed;

};
