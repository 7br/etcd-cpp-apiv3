#include <catch.hpp>
#include <iostream>

#include "etcd/Client.hpp"


TEST_CASE("lock and unlock")
{
  etcd::Client etcd("http://127.0.0.1:2379");

  // lock
  etcd::Response resp1 = etcd.lock("/test/abcd").get();
  CHECK("lock" == resp1.action());
  REQUIRE(resp1.is_ok());
  REQUIRE(0 == resp1.error_code());

  // unlock
  etcd::Response resp2 = etcd.unlock("/test/abcd").get();
  CHECK("unlock" == resp2.action());
  REQUIRE(resp2.is_ok());
  REQUIRE(0 == resp2.error_code());
}


TEST_CASE("double lock will fail")
{
  etcd::Client etcd("http://127.0.0.1:2379");
  // lock
  etcd::Response resp1 = etcd.lock("/test/abcd").get();
  CHECK("lock" == resp1.action());
  REQUIRE(resp1.is_ok());
  REQUIRE(0 == resp1.error_code());

  // lock again
  etcd::Response resp2 = etcd.lock("/test/abcd").get();
  CHECK("lock" == resp2.action());
  REQUIRE(!resp2.is_ok());

  // unlock
  etcd::Response resp3 = etcd.unlock("/test/abcd").get();
  CHECK("unlock" == resp3.action());
  REQUIRE(resp3.is_ok());
}
