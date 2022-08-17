from bluetooth import *
from pprint import pprint
nearby_devices = discover_devices(lookup_names=True)
pprint(nearby_devices)

# for dev in devices:
#     service = find_service(address=dev)
#     pprint(service)

# ['D4:68:AA:8F:E5:8E', '00:22:02:01:2F:00', '80:47:86:68:18:E7']
# service = find_service(address='80:47:86:68:18:E7')
# pprint(service)

# ['xx:yy:tt:zz:44:BD', '00:yy:72:zz:bb:aa']