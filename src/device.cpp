/*
    Copyright 2014-2015 Harald Sitter <sitter@kde.org>

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2.1 of the License, or (at your option) version 3, or any
    later version accepted by the membership of KDE e.V. (or its
    successor approved by the membership of KDE e.V.), which shall
    act as a proxy defined in Section 6 of version 3 of the license.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this library.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "device.h"

QPulseAudio::Device::State QPulseAudio::Device::state() const
{
    return m_state;
}

QString QPulseAudio::Device::name() const
{
    return m_name;
}

QString QPulseAudio::Device::description() const
{
    return m_description;
}

QString QPulseAudio::Device::formFactor() const
{
    return m_formFactor;
}

quint32 QPulseAudio::Device::cardIndex() const
{
    return m_cardIndex;
}

QList<QObject *> QPulseAudio::Device::ports() const
{
    return m_ports;
}

quint32 QPulseAudio::Device::activePortIndex() const
{
    return m_activePortIndex;
}

bool QPulseAudio::Device::isVirtualDevice() const
{
    return m_virtualDevice;
}

QPulseAudio::Device::Device(QObject *parent)
    : VolumeObject(parent)
{
}

QPulseAudio::Device::State QPulseAudio::Device::stateFromPaState(int value) const
{
    switch (value) {
    case -1: // PA_X_INVALID_STATE
        return InvalidState;
    case 0:  // PA_X_RUNNING
        return RunningState;
    case 1:  // PA_X_IDLE
        return IdleState;
    case 2:  // PA_X_SUSPENDED
        return SuspendedState;
    default:
        return UnknownState;
    }
}
