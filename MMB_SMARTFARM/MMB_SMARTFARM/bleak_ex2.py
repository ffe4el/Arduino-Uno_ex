import asyncio
from bleak import BleakScanner

async def run():
    # 검색 시작(with 사용)
    async with BleakScanner() as scanner:
        # 5초간 대기
        await asyncio.sleep(5.0)
        # 검색된 장치 얻어오기
        devices = await scanner.get_discovered_devices()
    # 리스트 출력
    for d in devices:
        print(d)

loop = asyncio.get_event_loop()
loop.run_until_complete(run())