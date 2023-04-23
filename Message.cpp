#include "Message.h"
#include "Computer.h"

Message::Message(Computer* source, Computer* destination, Time creationTime)
{
	_source = source;
	_destination = destination;
	_creationTime = creationTime;
	_destinationTime = -1;
	_waitTime = 0;
	_timesStopped = 0;
}

Message::~Message()
{
}

void Message::updateWaitTime(Time waitTime)
{
    _waitTime += waitTime;
    _timesStopped++;
}

void Message::reportStatistics() const
{
    std::cout << "Message statistics:" << std::endl;
    std::cout << "  Source: " << _source << std::endl;
    std::cout << "  Destination: " << _destination << std::endl;
    std::cout << "  Creation time: " << _creationTime << std::endl;
    std::cout << "  Destination time: " << _destinationTime << std::endl;
    std::cout << "  Wait time: " << _waitTime << std::endl;
    std::cout << "  Times stopped: " << _timesStopped << std::endl;
}

Computer* Message::getSource() const
{
    return _source;
}

Computer* Message::getDestination() const
{
    return _destination;
}

void Message::setDestination(Computer* computer) {
    _destination = computer;
}
