// Copyright (c) 2009-2012 The Bitcoin developers
// Copyright (c) 2011-2012 Litecoin Developers
// Copyright (c) 2013 Feathercoin Developers

// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <boost/assign/list_of.hpp> // for 'map_list_of()'
#include <boost/foreach.hpp>

#include "checkpoints.h"

#include "main.h"
#include "uint256.h"

namespace Checkpoints
{
    typedef std::map<int, uint256> MapCheckpoints;

    //
    // What makes a good checkpoint block?
    // + Is surrounded by blocks with reasonable timestamps
    //   (no blocks before with a timestamp after, none after with
    //    timestamp before)
    // + Contains no strange transactions
    //
    static MapCheckpoints mapCheckpoints =
            boost::assign::map_list_of
            (     0, uint256("0x0a2e3d22062632afa9c5143a41365a3914b6e198ba1879379083c06dffacf31d"))
            //(     1, uint256("0xfdbe99b90c90bae7505796461471d89ae8388ab953997aa06a355bbda8d915cb"))
            //(     22267, uint256("0x23dc7d871fc2a9b994112e978019f6370bab0b8979f557afe77a7ab620224b70"))
            //(     22847, uint256("0x1450b80c150fee1e657ee8309819276342c021fab5e6a20ccf5407f5e2218d0f"))
            //(     23453, uint256("0x7c25d3f9671e1d9400c9a1be2ff68e68db561ab85ae6b7020062d8d26da81e4c"))
            //(     28230, uint256("0xd3feb71f92c63c682f994d7c615adc425226c669a83d46012b32fc8d518b08bb"))
            //(     31846, uint256("0xba7d5c0e6d46f6448253290ce037e13975c13ca9c375ae854b6b2f85044fc0f9"))
            //(     33918, uint256("0x023cf4acfd8bf0114090a7ce048e79ac28152de78bb41f1277742904494e6c49"))
			//(     34000, uint256("0x082f5d9023af3f068733ab68cf81b741f58e3c75ae28d2a9bd07f30b74c38356"))
			//(     41300, uint256("0x8c4e02f6c0d20e856fd7e952a147fee30ce145ca6932a284f354924362d2b408"))
            ;


    bool CheckBlock(int nHeight, const uint256& hash)
    {
        if (fTestNet) return true; // Testnet has no checkpoints

        MapCheckpoints::const_iterator i = mapCheckpoints.find(nHeight);
        if (i == mapCheckpoints.end()) return true;
        //return hash == i->second;
		return true;
    }

    int GetTotalBlocksEstimate()
    {
        if (fTestNet) return 0;
        //return mapCheckpoints.rbegin()->first;
		return true;
    }

    CBlockIndex* GetLastCheckpoint(const std::map<uint256, CBlockIndex*>& mapBlockIndex)
    {
        if (fTestNet) return NULL;

        BOOST_REVERSE_FOREACH(const MapCheckpoints::value_type& i, mapCheckpoints)
        {
            const uint256& hash = i.second;
            std::map<uint256, CBlockIndex*>::const_iterator t = mapBlockIndex.find(hash);
            if (t != mapBlockIndex.end())
                //return t->second;
			return NULL;
        }
        return NULL;
    }

    uint256 GetLatestHardenedCheckpoint()
    {
        const MapCheckpoints& checkpoints = mapCheckpoints;
        return (checkpoints.rbegin()->second);
    }
}
