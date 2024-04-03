import packet_buffer;
import <iostream>;

using namespace std;

class IPPacket final
{
public:
	explicit IPPacket(int id) : m_id{ id } {}
	int getID() const { return m_id; }

private:
	int m_id;
};

int main()
{
	PacketBuffer<IPPacket> ipPackets{ 3 };

	// Add 4 packets
	for (int i{ 1 }; i <= 4; ++i) {
		if (!ipPackets.bufferPacket(IPPacket{ i })) {
			cout << "Packet " << i << " dropped (queue is full)." << endl;
		}
	}

	while (true) {
		try {
			IPPacket packet{ ipPackets.getNextPacket() };
			cout << "Processing packet " << packet.getID() << endl;
		} catch (const out_of_range&) {
			cout << "Queue is empty." << endl;
			break;
		}
	}
}
