/// @file
/// @brief Contains Switch::System::Net::WebResponse class.
#pragma once

#include "../../Types.hpp"
#include "../../RefPtr.hpp"
#include "../Object.hpp"
#include "../String.hpp"
#include "../IO/SeekOrigin.hpp"
#include "../IO/Stream.hpp"
#include "../Threading/AutoResetEvent.hpp"
#include "../Threading/ManualResetEvent.hpp"

/// @brief The Switch library contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Net namespace provides a simple programming interface for many of the protocols used on networks today.
    /// The WebRequest and WebResponse classes form the basis of what are called pluggable protocols, an implementation of network services that enables you to develop applications that use Internet resources without worrying about the specific details of the individual protocols.
    namespace Net {
      class WebRequest;

      class pcf_public WebResponse : public Object {
      public:
        class WebResponseStream: public System::IO::Stream {
        public:
          WebResponseStream() : Stream(1000, 1000) {}
          WebResponseStream(const WebResponseStream& wrs) : data(wrs.data) {}
          void SetWebRequest(System::Net::WebRequest* webRequest);
          
          void StartTransfert();
          
          int32 Read(void* handle, int32 count);
          int32 Read(Array<byte>& buffer, int32 offset, int32 count) override;
          void Write(const Array<byte>& buffer, int32 offset, int32 count) override { }
          int64 Seek(int64, System::IO::SeekOrigin) override;
          
          int32 Receive(const void* handle, int32 count);
          
          void EndTransfert();
          
          void Close() override;
          
        protected:
          friend class WebResponse;
          bool GetCanRead() const override {return true;}
          bool GetCanSeek()  const override {return false;}
          bool GetCanTimeout() const override {return true;}
          bool GetCanWrite() const override {return false;}
          int64 GetLength() const override {return 0;}
          int64 GetPosition() const override {return 0;}
          
        private:
          struct WebRequestStreamData {
            void* buffer = null;
            System::Net::WebRequest* webRequest = null;
            System::Threading::ManualResetEvent writeEvent {false};
            System::Threading::ManualResetEvent readEvent {true};
            int32 bufferSize = 0;
            int32 bufferOffset = 0;
            bool started = false;
            bool finished = false;
          };
          refptr<WebRequestStreamData> data = pcf_new<WebRequestStreamData>();
        };
        
        Property<int64> ContentLength {
          pcf_get {return this->GetContentLength();},
          pcf_set {this->SetContentLength(value);}
        };
        
        Property<string, ReadOnly> ContentType {
          pcf_get {return this->GetContentType();}
        };
        
        virtual ~WebResponse();

        virtual WebResponseStream GetResponseStream();
        
      protected:
        virtual int64 GetContentLength() const {return this->contentLength;}
        virtual void SetContentLength(const int64& contentLength) {this->contentLength = contentLength;}
        
        virtual String GetContentType() const {return this->contentType;}
        
        friend class WebRequest;
        friend class FtpWebRequest;
        
        WebResponse();
        WebResponse(const WebResponse& webResponse) = delete;
        WebResponse& operator =(const WebResponse& webResponse) = delete;
        

        int64 contentLength = 0;
        string contentType;

        void SetWebRequest(System::Net::WebRequest& webRequest);
        System::Net::WebRequest* webRequest = null;
        System::Net::WebResponse::WebResponseStream responseStream;

        static size_t WriteNullStream(void* buffer, size_t size, size_t nmemb, void* stream);
        static size_t WriteStream(void* buffer, size_t size, size_t nmemb, void* stream);
        virtual void EndTransfert();
        virtual void StartTransfert();
        virtual int64 GetResponseCode() const;
      };
    }
  }
}

using namespace Switch;
