# Serial

The serial protocol has a number of built-in rules - mechanisms that help ensure robust and error-free data transfers. These mechanisms are:

- Data bits

- Synchronization bits

- Parity bits

- Baud rate

Through the variety of these signaling mechanisms, you'll find that there's
no one way to send data serially. The protocol is highly configurable. The
critical part is making sure that both devices on a serial bus are configured
to use the exact same protocols.

We went over baud rate in the main week, but lets refresh over it again.

The baud rate specifies how fast data is sent over a serial line. It's usually expressed in units of bits-per-second (bps).

- If you invert the baud rate, you can find out just how long it takes to transmit a single bit. This value determines how long the transmitter holds a serial line high/low or at what period the receiving device samples its line.

## Baud Rates

Baud rates can be just about any value within reason. The only requirement is that both devices operate at the same rate. One of the more common baud rates, especially for simple stuff where speed isn't critical, is 9600 bps. The second most common rate (for high speeds) is 115200 baud.

![](https://lh5.googleusercontent.com/eh3OQKFcHO1J7l-ibZNKlGiRIMlTiE6EgbQ6kQCq3jqZj9FLXfOzYMQvgTzrh334v_YFqzOBJ8rKlNYU7tusgjCtCMGcGuBbTt22vtpqKaTTKJRqI4rIESo_JemQbhlppj21gZDGYjvnTpCjS0XlfX49pxcWWOT2=s2048)

## Data Frame

Each block (usually a byte) of data transmitted is actually sent in a packet or frame of bits. Frames are created by appending synchronization and parity bits to our data.

![](https://lh6.googleusercontent.com/i5cVpzfRRgbDy12plAeTEtl27vbCscJkiGzQJPBjKa_mLC8hToc474kbq94b2i_K_YjO0b7KHwzB9V7oqpsBUYfr2NzQ3y021AzXf6nI5w46Lmz70O6TgGOqGDpkiS9l8o6zzqDyfiaY6EkqWyh1ntz6In_aAVkz=s2048)

#### Data Chunk

The real core of any serial packet is the data it carries, this chunk can vary in size from 5 to 9 bits, but in most applications will be a byte, as that is what most applications require.

#### Sync Bits

The synchronization bits are two or three special bits transferred with each chunk of data. They are the start bit and the stop bit(s). True to their name, these bits mark the beginning and end of a packet.

- There's always only one start bit, but the number of stop bits is configurable to either one or two (though it's commonly left at one).

The start bit is always indicated by an idle data line going from 1 to 0, while the stop bit(s) will transition back to the idle state by holding the line at 1.

#### Parity Bits

Parity is a form of very simple, low-level error checking. It comes in two flavors: odd or even. 

To produce the parity bit, all 5-9 bits of the data byte are added up, and the evenness of the sum decides whether the bit is set or not. 

Ex. Parity is set to even and is being added to a data byte like 0b01011101, which has an odd number of 1's (5). The parity bit would be set to 1. Conversely, if the parity mode was set to odd, the parity bit would be 0.

You can read more about parity bits [here](https://en.wikipedia.org/wiki/Parity_bit)

## Example

Note: This example uses 9600 8N1 - 9600 baud, 8 data bits, no parity, and 1 stop bit.

A device transmitting the ASCII characters 'O' and 'K' would have to create two packets of data. The ASCII value of O (that's uppercase) is 79, which breaks down into an 8-bit binary value of 01001111, while K's binary value is 01001011. All that's left is appending sync bits.

It isn't specifically stated, but it’s assumed that data is transferred [least-significant](https://en.wikipedia.org/wiki/Bit_numbering) bit first. Notice how each of the two bytes is sent as it reads from right-to-left.

![](https://lh3.googleusercontent.com/-e1Ck4hchEjeV0s458IUWHxWALPnL4F8lMTA6o2QpVvqk4M5-5mPTxPekRuHyBzjMnocYCYTYnoD7axdjrX4xwuJUsKsNaMtBTpwMXChB5wRLZ41mhpbUilArZVijhWHRvtH9O2Ns-vB3SL7pfn-b9HzM1i3SH55=s2048)
