/*!
 * \file MarketDataIF.hpp
 * \project BetterQuant
 *
 * \author byrnexu
 * \date 2022/09/08
 *
 * \brief
 */

#pragma once

#include "SHMHeader.hpp"
#include "def/BQConstIF.hpp"
#include "def/BQDefIF.hpp"

namespace bq {

struct MDHeader {
  std::uint64_t exchTs_;
  std::uint64_t localTs_;
  MarketCode marketCode_;
  SymbolType symbolType_;
  char symbolCode_[MAX_SYMBOL_CODE_LEN];
  MDType mdType_;
  std::string toStr() const;
  std::string getTopicPrefix() const;
};

struct Trades {
  SHMHeader shmHeader_;
  MDHeader mdHeader_;
  std::uint64_t tradeTs_;
  char tradeId_[MAX_TRADE_ID_LEN];
  Decimal price_;
  Decimal size_;
  Side side_;
  std::uint16_t extDataLen_{0};
  char extData_[0];
  std::string toStr() const;
};
using TradesSPtr = std::shared_ptr<Trades>;
using TradesUPtr = std::unique_ptr<Trades>;

struct Depth {
  Decimal price_;
  Decimal size_;
  std::uint32_t orderNum_;
};

struct Books {
  SHMHeader shmHeader_;
  MDHeader mdHeader_;
  Depth asks_[MAX_DEPTH_LEVEL];
  Depth bids_[MAX_DEPTH_LEVEL];
  std::string toStr() const;
  std::uint16_t extDataLen_{0};
  char extData_[0];
};
using BooksSPtr = std::shared_ptr<Books>;
using BooksUPtr = std::unique_ptr<Books>;

struct Tickers {
  SHMHeader shmHeader_;
  MDHeader mdHeader_;
  Decimal lastPrice_;
  Decimal lastSize_;
  Decimal askPrice_;
  Decimal askSize_;
  Decimal bidPrice_;
  Decimal bidSize_;
  Decimal open24h_;
  Decimal high24h_;
  Decimal low24h_;
  Decimal vol24h_;
  Decimal amt24h_;
  std::uint16_t extDataLen_{0};
  char extData_[0];
  std::string toStr() const;
};
using TickersSPtr = std::shared_ptr<Tickers>;
using TickersUPtr = std::unique_ptr<Tickers>;

struct Candle {
  SHMHeader shmHeader_;
  MDHeader mdHeader_;
  std::uint64_t startTs_;
  Decimal open_;
  Decimal high_;
  Decimal low_;
  Decimal close_;
  Decimal vol_;
  Decimal amt_;
  std::uint16_t extDataLen_{0};
  char extData_[0];
  std::string toStr() const;
};
using CandleSPtr = std::shared_ptr<Candle>;
using CandleUPtr = std::unique_ptr<Candle>;

}  // namespace bq
