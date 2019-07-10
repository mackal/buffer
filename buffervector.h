#ifndef BUFFER3_H
#define BUFFER3_H

#include <cstring>
#include <cassert>
#include <cstdint>
#include <string>
#include <algorithm>
#include <utility>
#include <vector>
#include <stdexcept>

class SerializeBuffer3 {
public:
    SerializeBuffer3() : m_pos(0) {}

    explicit SerializeBuffer3(size_t size) : m_pos(0)
    { m_data.resize(size, 0); }

    void WriteUInt8(uint8_t v) {
        if (Length() < m_pos + sizeof(uint8_t)) {
            if (!Resize(m_pos + sizeof(uint8_t))) {
                throw std::out_of_range("Packet::PutUInt8(), could not resize packet and would of written past the end.");
            }
        }
        *(uint8_t*)((char*)Data() + m_pos) = v;
        m_pos += sizeof(uint8_t);
    }

    void WriteUInt16(uint16_t v) {
        if (Length() < m_pos + sizeof(uint16_t)) {
            if (!Resize(m_pos + sizeof(uint16_t))) {
                throw std::out_of_range("Packet::PutUInt16(), could not resize packet and would of written past the end.");
            }
        }
        *(uint16_t*)((char*)Data() + m_pos) = v;
        m_pos += sizeof(uint16_t);
    }

    void WriteUInt32(uint32_t v) {
        if (Length() < m_pos + sizeof(uint32_t)) {
            if (!Resize(m_pos + sizeof(uint32_t))) {
                throw std::out_of_range("Packet::PutUInt32(), could not resize packet and would of written past the end.");
            }
        }
        *(uint32_t*)((char*)Data() + m_pos) = v;
        m_pos += sizeof(uint32_t);
    }

    void WriteUInt64(uint64_t v) {
        if (Length() < m_pos + sizeof(uint64_t)) {
            if (!Resize(m_pos + sizeof(uint64_t))) {
                throw std::out_of_range("Packet::PutUInt64(), could not resize packet and would of written past the end.");
            }
        }
        *(uint64_t*)((char*)Data() + m_pos) = v;
        m_pos += sizeof(uint64_t);
    }

    void WriteInt8(int8_t v) {
        if (Length() < m_pos + sizeof(int8_t)) {
            if (!Resize(m_pos + sizeof(int8_t))) {
                throw std::out_of_range("Packet::PutInt8(), could not resize packet and would of written past the end.");
            }
        }
        *(int8_t*)((char*)Data() + m_pos) = v;
        m_pos += sizeof(int8_t);
    }

    void WriteInt16(int16_t v) {
        if (Length() < m_pos + sizeof(int16_t)) {
            if (!Resize(m_pos + sizeof(int16_t))) {
                throw std::out_of_range("Packet::PutInt16(), could not resize packet and would of written past the end.");
            }
        }
        *(int16_t*)((char*)Data() + m_pos) = v;
        m_pos += sizeof(int16_t);
    }

    void WriteInt32(int32_t v) {
        if (Length() < m_pos + sizeof(int32_t)) {
            if (!Resize(m_pos + sizeof(int32_t))) {
                throw std::out_of_range("Packet::PutInt32(), could not resize packet and would of written past the end.");
            }
        }
        *(int32_t*)((char*)Data() + m_pos) = v;
        m_pos += sizeof(int32_t);
    }

    void WriteInt64(int64_t v) {
        if (Length() < m_pos + sizeof(int64_t)) {
            if (!Resize(m_pos + sizeof(int64_t))) {
                throw std::out_of_range("Packet::PutInt64(), could not resize packet and would of written past the end.");
            }
        }
        *(int64_t*)((char*)Data() + m_pos) = v;
        m_pos += sizeof(int64_t);
    }

    void WriteFloat(float v) {
        if (Length() < m_pos + sizeof(float)) {
            if (!Resize(m_pos + sizeof(float))) {
                throw std::out_of_range("Packet::PutFloat(), could not resize packet and would of written past the end.");
            }
        }
        *(float*)((char*)Data() + m_pos) = v;
        m_pos += sizeof(float);
    }

    void WriteDouble(double v) {
        if (Length() < m_pos + sizeof(double)) {
            if (!Resize(m_pos + sizeof(double))) {
                throw std::out_of_range("Packet::PutDouble(), could not resize packet and would of written past the end.");
            }
        }
        *(double*)((char*)Data() + m_pos) = v;
        m_pos += sizeof(double);
    }

    void WriteString(const char *str) {
        assert(str != nullptr);
        auto len = strlen(str) + 1;
        if (Length() < m_pos + len) {
            if (!Resize(m_pos + len))
                throw std::out_of_range("Packet::PutString(), could not resize packet and would of written past the end.");
        }
        memcpy(((char*)Data() + m_pos), str, len);
        m_pos += len;
    }

    void WriteString(const std::string &str) {
        auto len = str.length() + 1;
        if (Length() < m_pos + len) {
            if (!Resize(m_pos + len))
                throw std::out_of_range("Packet::PutString(), could not resize packet and would of written past the end.");
        }
        memcpy(((char*)Data() + m_pos), str.c_str(), len);
        m_pos += len;
    }

    void WriteLengthString(uint32_t len, const char *str) {
        assert(str != nullptr);
        if (Length() < m_pos + len + sizeof(uint32_t)) {
            if (!Resize(m_pos + len + sizeof(uint32_t)))
                throw std::out_of_range("Packet::PutString(), could not resize packet and would of written past the end.");
        }
        *(uint32_t*)((char*)Data() + m_pos) = len;
        m_pos += sizeof(uint32_t);
        memcpy(((char*)Data() + m_pos), str, len);
        m_pos += len;
    }

    size_t size() const { return m_pos; }
    size_t length() const { return size(); }
    size_t Length() { return m_data.size(); }
    size_t Length() const { return m_data.size(); }
    size_t capacity() const { return m_data.capacity(); }
    unsigned char *buffer() const { return (unsigned char *)Data(); }
    void *Data() { return &m_data[0]; }
    const void *Data() const { return &m_data[0]; }

    bool Resize(size_t new_size) { m_data.resize(new_size, 0); return true; }
    std::vector<unsigned char> m_data;
    size_t m_pos;
};

#endif /* !BUFFER3_H */
