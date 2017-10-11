// Copyright (c) 2009-2012 The Bitcoin developers
// Copyright (c) 2011-2012 Litecoin Developers
// Copyright (c) 2017 Xcash Developers
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
   /* static MapCheckpoints mapCheckpoints =
        boost::assign::map_list_of // TODO: needs to adjusted for checkpoint checks, also see main.cpp
        (         1, uint256("0xf2449e84c911aabb5389d2460ad3d4fd171c87bbdff45b65cb55713728e598f8"))
        (         2, uint256("0x43682e5929c9234209db6592953347aa8b4c8e233692369a61b4780b80835c42"))
        (     34336, uint256("0xfc6a3ee59b9f2429114178ff7a4792a7af102688156d26a3edbb90c243850dcd"))
        (     50000, uint256("0x5fa3d8bb008a55a1b6e301b435be3a68985083435748b913ef8572bf1282303c"))
        (     70000, uint256("0x7ee7864ffec5a23f526e01a1388a6e988d2773365522e04dd51d3c71c19b459f"))
        ;
*/
    static MapCheckpoints mapCheckpoints =
            boost::assign::map_list_of
            (151167, uint256("0x00000b8e36a4b9ccdfec4bb0ea49f657d5634c57bb043e4b0a27e4c58552a1ef"))
            (148106, uint256("0x00000942b6bd5f734da563c47cd5ebc5d19207bdbe2e38a7f32910e2a3bcf235"))
            (712145, uint256("0x0000010632bb5250e8c9fe7039a0769d9c5faa2013e705e73232d43b34016814"))
            ( 35782, uint256("0x0000065f87fc6b82e1a2b3568c58a6825967e6226826877c1cd425c68d7fc5f6"))
            (631117, uint256("0x0000045a837d3ff5f037e7f22172a7381a99d73dce7f26628f784bf44796a70a"))
            ( 39771, uint256("0x00000e6df4ed1b8bf0a9a5113bf486b5a45d5b56d962aa182dfc2be26dcc92e3"))
            (118476, uint256("0x000007b909adf3187828ee32b75b262de3e9dbc57d69998ec892e6e181ddbf71"))
            (173352, uint256("0x00000d3dce4ad0850080ba784cd888779d8d2b75fda893e7f0060c5bec1c7cea"))
            ;


    bool CheckBlock(int nHeight, const uint256& hash)
    {
        if (fTestNet) return true; // Testnet has no checkpoints

        MapCheckpoints::const_iterator i = mapCheckpoints.find(nHeight);
        if (i == mapCheckpoints.end()) return true;
        return hash == i->second;
    }

    int GetTotalBlocksEstimate()
    {
        if (fTestNet) return 0;
        return mapCheckpoints.rbegin()->first;
        //return 0;
    }

    CBlockIndex* GetLastCheckpoint(const std::map<uint256, CBlockIndex*>& mapBlockIndex)
    {
        if (fTestNet) return NULL;

        BOOST_REVERSE_FOREACH(const MapCheckpoints::value_type& i, mapCheckpoints)
        {
            const uint256& hash = i.second;
            std::map<uint256, CBlockIndex*>::const_iterator t = mapBlockIndex.find(hash);
            if (t != mapBlockIndex.end())
              return t->second;
             //return NULL;
        }
        return NULL;
    }
}
