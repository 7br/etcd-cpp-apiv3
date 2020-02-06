#ifndef __ASYNC_LOCK_HPP__
#define __ASYNC_LOCK_HPP__

#include <grpc++/grpc++.h>
#include "proto/rpc.grpc.pb.h"
#include "proto/rpc.pb.h"
#include "v3/include/V3Response.hpp"


using grpc::ClientAsyncResponseReader;
using etcdserverpb::LockRequest;
using etcdserverpb::LockResponse;
using etcdserverpb::UnlockRequest;
using etcdserverpb::UnlockResponse;
using etcdserverpb::KV;

namespace etcdv3
{
  class AsyncLockResponse : public etcdv3::V3Response
  {
    public:
      AsyncLockResponse(){};
      void ParseResponse(LockResponse& resp);
  };

  class AsyncUnlockResponse : public etcdv3::V3Response
  {
    public:
      AsyncUnlockResponse(){};
      void ParseResponse(UnlockResponse& resp);
  };
}

#endif

