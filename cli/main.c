#include <libevdev-1.0/libevdev/libevdev.h> 
// #include <libevdev-1.0/libevdev/libevdev-uinput.h> 
#include <unistd.h>
#include <fcntl.h>
#include <stddef.h>
#include <stdio.h>

int main(void) {

  struct libevdev *dev = NULL;
  int fd;
  int rc = 1;
  
  fd = open("/dev/input/event22", O_RDONLY|O_NONBLOCK);
  rc = libevdev_new_from_fd(fd, &dev);
  
  printf("Input device name: \"%s\"\n", libevdev_get_name(dev));
  printf("Input device ID: bus %#x vendor %#x product %#x\n",
         libevdev_get_id_bustype(dev),
         libevdev_get_id_vendor(dev),
         libevdev_get_id_product(dev));
  
  return 0;
}
