#include "mod/MyMod.h"

#include <ll/api/memory/Hook.h>
#include <mc/world/level/BlockPos.h>
#include <mc/world/level/BlockSource.h>
#include <mc/world/level/Level.h>
#include <mc/world/level/block/BlockLegacy.h>
#include <mc/world/level/block/SkullBlock.h>
#include <mc/world/level/dimension/Dimension.h>

namespace lk {

LL_TYPE_INSTANCE_HOOK(
    SkullBlockCheckMobSpawnHook,
    HookPriority::Normal,
    SkullBlock,
    &SkullBlock::checkMobSpawn,
    bool,
    ::Level&          level,
    ::BlockSource&    region,
    ::BlockPos const& pos
) {
    // auto& logger = MyMod::getInstance().getSelf().getLogger();
    // logger.info("hookWitherSummonBefore {} {}", region.mDimension.mId->id, pos.toString());
    if (region.mDimension.mId->id == 0) return false;
    auto r = origin(level, region, pos);
    // logger.info("hookWitherSummonAfter {}", r);
    return r;
}

void hook() { SkullBlockCheckMobSpawnHook::hook(); }

} // namespace lk