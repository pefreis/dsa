class ParkingSpace:
    def __init__(self, start: int, size: int):
        self.start = start
        self.size = size
        self.prev = None
        self.next = None
    
    def fits(self, size: int) -> bool:
        return self.size >= size

    def end(self) -> int:
        return self.start + self.size

    def include(self, new: 'ParkingSpace'):
        if self.next is None or new.end() <= self.next.start:
            self.insert_after(new)
            self.merge_spaces()
        else:
            self.next.include(new)
    
    def insert_after(self, new: 'ParkingSpace'):
        tmp = self.next
        self.next = new
        new.prev = self
        new.next = tmp
        if tmp is not None:
            tmp.prev = new
    
    def merge_spaces(self):
        if self.next is None:
            return
        
        if self.end() != self.next.start:
            self.next.merge_spaces()
            return

        self.size += self.next.size
        tmp = self.next.next
        self.next = tmp
        if tmp is not None:
            tmp.prev = self
        
        self.merge_spaces()

    def park(self, size: int):
        self.start += size
        self.size -= size
        if self.size == 0:
            tmp = self.next
            self.prev.next = tmp


class ParkingLot:
    def __init__(self, size: int):
        self.spaces = ParkingSpace(-1, 0)
        self.spaces.include(ParkingSpace(0, size))
        self.parked = {}
        self.billing = 0

    def process_event(self, event: str):
        e_type, car_info = event.split(' ', 1)
        if e_type == 'C':
            car_plate, car_size = car_info.split(' ')
            car_plate = int(car_plate)
            car_size = int(car_size)
            ok = self.try_park(car_plate, car_size)
            if ok: self.billing += 10
        elif e_type == 'S':
            car_plate = int(car_info)
            self.unpark(car_plate)

    def try_park(self, car_plate: int, car_size: int) -> bool:
        it = self.spaces
        while it is not None:            
            if it.fits(car_size):
                self.parked[car_plate] = (it.start, car_size)
                it.park(car_size)
                return True
            
            it = it.next
        
        return False

    def unpark(self, car_plate: int):
        if car_plate in self.parked:
            parked = self.parked[car_plate]
            self.spaces.include(ParkingSpace(parked[0], parked[1]))
            del self.parked[car_plate]

while True:
    try:
        inp = input()
        if inp == '': break

        size, num_evts = inp.split(' ', 1)
        size = int(size)
        num_evts = int(num_evts)

        p = ParkingLot(size)
        for _ in range(num_evts):
            p.process_event(input())
        
        print(p.billing)

    except EOFError:
        break
