#include <benchmark/benchmark.h>
#include "buffer.h"
#include "buffercxx.h"
#include "buffervector.h"

static void bench_c_nopre_alloc(benchmark::State &state)
{
    SerializeBuffer buf;
    benchmark::DoNotOptimize(buf);
    while (state.KeepRunning()) {
        buf = SerializeBuffer();
    }
}

static void bench_c_nopre(benchmark::State &state)
{
    SerializeBuffer buf;
    benchmark::DoNotOptimize(buf.m_buffer);
    while (state.KeepRunning()) {
        buf.WriteInt32(2);
        buf.WriteInt32(0);
        buf.WriteInt32(7964);

        buf.WriteInt32(5062);
        buf.WriteFloat(1.0f);
        buf.WriteInt32(0);
        buf.WriteInt32(1);
        buf.WriteString("Goblin Broth");
        buf.WriteString("It would seem that little bit of fat from goblin flesh is a good for our stock that we bring to Norrath's Keepers, especially the ones from Stillmoon Temple.  It would seem it provides us with some resistances to the extreme conditions here. Go %1.");
        buf.WriteInt8(0);

        buf.WriteInt32(1);
        buf.WriteInt32(0);
        buf.WriteInt32(3);
        buf.WriteInt32(0);
        buf.WriteString("");
        buf.WriteLengthString(19, "Mottled Goblin Meat");
        buf.WriteInt32(7);
        buf.WriteLengthString(2, "-1");
        buf.WriteLengthString(1, "0");
        buf.WriteString("");
        buf.WriteString("");
        buf.WriteString("0");

        buf.WriteInt32(5064);
        buf.WriteFloat(1.0f);
        buf.WriteInt32(0);
        buf.WriteInt32(1);
        buf.WriteString("Blood of the Winged");
        buf.WriteString("The blood of the drake is used for by the Norrath's Keepers to create potions that wards against some magical attacks.  It serves them in the dragon lands. It would help me and them if you gather some from Lavaspinner's Lair.");
        buf.WriteInt8(0);

        buf.WriteInt32(1);
        buf.WriteInt32(0);
        buf.WriteInt32(3);
        buf.WriteInt32(0);
        buf.WriteString("");
        buf.WriteLengthString(20, "Frothing Drake Blood");
        buf.WriteInt32(6);
        buf.WriteLengthString(2, "-1");
        buf.WriteLengthString(1, "0");
        buf.WriteString("");
        buf.WriteString("");
        buf.WriteString("0");
        buf = SerializeBuffer();
    }
}

static void bench_cxx_nopre_alloc(benchmark::State &state)
{
    SerializeBuffer2 buf;
    benchmark::DoNotOptimize(buf);
    while (state.KeepRunning()) {
        buf = SerializeBuffer2();
    }
}

static void bench_cxx_nopre(benchmark::State &state)
{
    SerializeBuffer2 buf;
    benchmark::DoNotOptimize(buf.m_buffer);
    while (state.KeepRunning()) {
        buf.WriteInt32(2);
        buf.WriteInt32(0);
        buf.WriteInt32(7964);

        buf.WriteInt32(5062);
        buf.WriteFloat(1.0f);
        buf.WriteInt32(0);
        buf.WriteInt32(1);
        buf.WriteString("Goblin Broth");
        buf.WriteString("It would seem that little bit of fat from goblin flesh is a good for our stock that we bring to Norrath's Keepers, especially the ones from Stillmoon Temple.  It would seem it provides us with some resistances to the extreme conditions here. Go %1.");
        buf.WriteInt8(0);

        buf.WriteInt32(1);
        buf.WriteInt32(0);
        buf.WriteInt32(3);
        buf.WriteInt32(0);
        buf.WriteString("");
        buf.WriteLengthString(19, "Mottled Goblin Meat");
        buf.WriteInt32(7);
        buf.WriteLengthString(2, "-1");
        buf.WriteLengthString(1, "0");
        buf.WriteString("");
        buf.WriteString("");
        buf.WriteString("0");

        buf.WriteInt32(5064);
        buf.WriteFloat(1.0f);
        buf.WriteInt32(0);
        buf.WriteInt32(1);
        buf.WriteString("Blood of the Winged");
        buf.WriteString("The blood of the drake is used for by the Norrath's Keepers to create potions that wards against some magical attacks.  It serves them in the dragon lands. It would help me and them if you gather some from Lavaspinner's Lair.");
        buf.WriteInt8(0);

        buf.WriteInt32(1);
        buf.WriteInt32(0);
        buf.WriteInt32(3);
        buf.WriteInt32(0);
        buf.WriteString("");
        buf.WriteLengthString(20, "Frothing Drake Blood");
        buf.WriteInt32(6);
        buf.WriteLengthString(2, "-1");
        buf.WriteLengthString(1, "0");
        buf.WriteString("");
        buf.WriteString("");
        buf.WriteString("0");
        buf = SerializeBuffer2();
    }
}

static void bench_c_pre_alloc(benchmark::State &state)
{
    SerializeBuffer buf(50);
    benchmark::DoNotOptimize(buf);
    while (state.KeepRunning()) {
        buf = SerializeBuffer(50);
    }
}

static void bench_c_pre(benchmark::State &state)
{
    SerializeBuffer buf(50);
    benchmark::DoNotOptimize(buf.m_buffer);
    while (state.KeepRunning()) {
        buf.WriteInt32(2);
        buf.WriteInt32(0);
        buf.WriteInt32(7964);

        buf.WriteInt32(5062);
        buf.WriteFloat(1.0f);
        buf.WriteInt32(0);
        buf.WriteInt32(1);
        buf.WriteString("Goblin Broth");
        buf.WriteString("It would seem that little bit of fat from goblin flesh is a good for our stock that we bring to Norrath's Keepers, especially the ones from Stillmoon Temple.  It would seem it provides us with some resistances to the extreme conditions here. Go %1.");
        buf.WriteInt8(0);

        buf.WriteInt32(1);
        buf.WriteInt32(0);
        buf.WriteInt32(3);
        buf.WriteInt32(0);
        buf.WriteString("");
        buf.WriteLengthString(19, "Mottled Goblin Meat");
        buf.WriteInt32(7);
        buf.WriteLengthString(2, "-1");
        buf.WriteLengthString(1, "0");
        buf.WriteString("");
        buf.WriteString("");
        buf.WriteString("0");

        buf.WriteInt32(5064);
        buf.WriteFloat(1.0f);
        buf.WriteInt32(0);
        buf.WriteInt32(1);
        buf.WriteString("Blood of the Winged");
        buf.WriteString("The blood of the drake is used for by the Norrath's Keepers to create potions that wards against some magical attacks.  It serves them in the dragon lands. It would help me and them if you gather some from Lavaspinner's Lair.");
        buf.WriteInt8(0);

        buf.WriteInt32(1);
        buf.WriteInt32(0);
        buf.WriteInt32(3);
        buf.WriteInt32(0);
        buf.WriteString("");
        buf.WriteLengthString(20, "Frothing Drake Blood");
        buf.WriteInt32(6);
        buf.WriteLengthString(2, "-1");
        buf.WriteLengthString(1, "0");
        buf.WriteString("");
        buf.WriteString("");
        buf.WriteString("0");
        buf = SerializeBuffer(50);
    }
}

static void bench_cxx_pre_alloc(benchmark::State &state)
{
    SerializeBuffer2 buf(50);
    benchmark::DoNotOptimize(buf);
    while (state.KeepRunning()) {
        buf = SerializeBuffer2(50);
    }
}

static void bench_cxx_pre(benchmark::State &state)
{
    SerializeBuffer2 buf(50);
    benchmark::DoNotOptimize(buf.m_buffer);
    while (state.KeepRunning()) {
        buf.WriteInt32(2);
        buf.WriteInt32(0);
        buf.WriteInt32(7964);

        buf.WriteInt32(5062);
        buf.WriteFloat(1.0f);
        buf.WriteInt32(0);
        buf.WriteInt32(1);
        buf.WriteString("Goblin Broth");
        buf.WriteString("It would seem that little bit of fat from goblin flesh is a good for our stock that we bring to Norrath's Keepers, especially the ones from Stillmoon Temple.  It would seem it provides us with some resistances to the extreme conditions here. Go %1.");
        buf.WriteInt8(0);

        buf.WriteInt32(1);
        buf.WriteInt32(0);
        buf.WriteInt32(3);
        buf.WriteInt32(0);
        buf.WriteString("");
        buf.WriteLengthString(19, "Mottled Goblin Meat");
        buf.WriteInt32(7);
        buf.WriteLengthString(2, "-1");
        buf.WriteLengthString(1, "0");
        buf.WriteString("");
        buf.WriteString("");
        buf.WriteString("0");

        buf.WriteInt32(5064);
        buf.WriteFloat(1.0f);
        buf.WriteInt32(0);
        buf.WriteInt32(1);
        buf.WriteString("Blood of the Winged");
        buf.WriteString("The blood of the drake is used for by the Norrath's Keepers to create potions that wards against some magical attacks.  It serves them in the dragon lands. It would help me and them if you gather some from Lavaspinner's Lair.");
        buf.WriteInt8(0);

        buf.WriteInt32(1);
        buf.WriteInt32(0);
        buf.WriteInt32(3);
        buf.WriteInt32(0);
        buf.WriteString("");
        buf.WriteLengthString(20, "Frothing Drake Blood");
        buf.WriteInt32(6);
        buf.WriteLengthString(2, "-1");
        buf.WriteLengthString(1, "0");
        buf.WriteString("");
        buf.WriteString("");
        buf.WriteString("0");
        buf = SerializeBuffer2(50);
    }
}

static void bench_v_nopre_alloc(benchmark::State &state)
{
    SerializeBuffer3 buf;
    benchmark::DoNotOptimize(buf);
    while (state.KeepRunning()) {
        buf = SerializeBuffer3();
    }
}

static void bench_v_nopre(benchmark::State &state)
{
    SerializeBuffer3 buf;
    benchmark::DoNotOptimize(buf.m_data.data());
    while (state.KeepRunning()) {
        buf.WriteInt32(2);
        buf.WriteInt32(0);
        buf.WriteInt32(7964);

        buf.WriteInt32(5062);
        buf.WriteFloat(1.0f);
        buf.WriteInt32(0);
        buf.WriteInt32(1);
        buf.WriteString("Goblin Broth");
        buf.WriteString("It would seem that little bit of fat from goblin flesh is a good for our stock that we bring to Norrath's Keepers, especially the ones from Stillmoon Temple.  It would seem it provides us with some resistances to the extreme conditions here. Go %1.");
        buf.WriteInt8(0);

        buf.WriteInt32(1);
        buf.WriteInt32(0);
        buf.WriteInt32(3);
        buf.WriteInt32(0);
        buf.WriteString("");
        buf.WriteLengthString(19, "Mottled Goblin Meat");
        buf.WriteInt32(7);
        buf.WriteLengthString(2, "-1");
        buf.WriteLengthString(1, "0");
        buf.WriteString("");
        buf.WriteString("");
        buf.WriteString("0");

        buf.WriteInt32(5064);
        buf.WriteFloat(1.0f);
        buf.WriteInt32(0);
        buf.WriteInt32(1);
        buf.WriteString("Blood of the Winged");
        buf.WriteString("The blood of the drake is used for by the Norrath's Keepers to create potions that wards against some magical attacks.  It serves them in the dragon lands. It would help me and them if you gather some from Lavaspinner's Lair.");
        buf.WriteInt8(0);

        buf.WriteInt32(1);
        buf.WriteInt32(0);
        buf.WriteInt32(3);
        buf.WriteInt32(0);
        buf.WriteString("");
        buf.WriteLengthString(20, "Frothing Drake Blood");
        buf.WriteInt32(6);
        buf.WriteLengthString(2, "-1");
        buf.WriteLengthString(1, "0");
        buf.WriteString("");
        buf.WriteString("");
        buf.WriteString("0");
        buf = SerializeBuffer3();
    }
}

static void bench_v_pre_alloc(benchmark::State &state)
{
    SerializeBuffer3 buf(50);
    benchmark::DoNotOptimize(buf);
    while (state.KeepRunning()) {
        buf = SerializeBuffer3(50);
    }
}

static void bench_v_pre(benchmark::State &state)
{
    SerializeBuffer3 buf(50);
    benchmark::DoNotOptimize(buf.m_data.data());
    while (state.KeepRunning()) {
        buf.WriteInt32(2);
        buf.WriteInt32(0);
        buf.WriteInt32(7964);

        buf.WriteInt32(5062);
        buf.WriteFloat(1.0f);
        buf.WriteInt32(0);
        buf.WriteInt32(1);
        buf.WriteString("Goblin Broth");
        buf.WriteString("It would seem that little bit of fat from goblin flesh is a good for our stock that we bring to Norrath's Keepers, especially the ones from Stillmoon Temple.  It would seem it provides us with some resistances to the extreme conditions here. Go %1.");
        buf.WriteInt8(0);

        buf.WriteInt32(1);
        buf.WriteInt32(0);
        buf.WriteInt32(3);
        buf.WriteInt32(0);
        buf.WriteString("");
        buf.WriteLengthString(19, "Mottled Goblin Meat");
        buf.WriteInt32(7);
        buf.WriteLengthString(2, "-1");
        buf.WriteLengthString(1, "0");
        buf.WriteString("");
        buf.WriteString("");
        buf.WriteString("0");

        buf.WriteInt32(5064);
        buf.WriteFloat(1.0f);
        buf.WriteInt32(0);
        buf.WriteInt32(1);
        buf.WriteString("Blood of the Winged");
        buf.WriteString("The blood of the drake is used for by the Norrath's Keepers to create potions that wards against some magical attacks.  It serves them in the dragon lands. It would help me and them if you gather some from Lavaspinner's Lair.");
        buf.WriteInt8(0);

        buf.WriteInt32(1);
        buf.WriteInt32(0);
        buf.WriteInt32(3);
        buf.WriteInt32(0);
        buf.WriteString("");
        buf.WriteLengthString(20, "Frothing Drake Blood");
        buf.WriteInt32(6);
        buf.WriteLengthString(2, "-1");
        buf.WriteLengthString(1, "0");
        buf.WriteString("");
        buf.WriteString("");
        buf.WriteString("0");
        buf = SerializeBuffer3(50);
    }
}

BENCHMARK(bench_c_nopre_alloc);
BENCHMARK(bench_c_nopre);
BENCHMARK(bench_cxx_nopre_alloc);
BENCHMARK(bench_cxx_nopre);
BENCHMARK(bench_v_nopre_alloc);
BENCHMARK(bench_v_nopre);
BENCHMARK(bench_c_pre_alloc);
BENCHMARK(bench_c_pre);
BENCHMARK(bench_cxx_pre_alloc);
BENCHMARK(bench_cxx_pre);
BENCHMARK(bench_v_pre_alloc);
BENCHMARK(bench_v_pre);

BENCHMARK_MAIN();
