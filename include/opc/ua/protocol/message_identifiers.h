/// @author Alexander Rykovanov 2013
/// @email rykovanov.as@gmail.com
/// @brief Opc binary cnnection channel.
/// @license GNU LGPL
///
/// Distributed under the GNU LGPL License
/// (See accompanying file LICENSE or copy at
/// http://www.gnu.org/licenses/lgpl.html)
///

#ifndef __OPC_UA_BINARY_MESSAGE_IdENTIFIERS
#define __OPC_UA_BINARY_MESSAGE_IdENTIFIERS

namespace OpcUa
{
  enum MessageId
  {
    INVALID = 0,

    ACTIVATE_SESSION_REQUEST   = 0x1d3, //467;
    ACTIVATE_SESSION_RESPONSE = 0x1d6, //470;

    BROWSE_REQUEST  = 0x20f, // 527;
    BROWSE_RESPONSE = 0x212, //530;

    BROWSE_NEXT_REQUEST  = 0x215, // 533
    BROWSE_NEXT_RESPONSE = 0x218, // 536

    CLOSE_SECURE_CHANNEL_REQUEST = 0x1c4, // 452

    CLOSE_SESSION_REQUEST  = 0x1d9, // 473;
    CLOSE_SESSION_RESPONSE = 0x1dc, // 476;

    // Session services
    CREATE_SESSION_REQUEST  = 0x1cd, // 461;
    CREATE_SESSION_RESPONSE = 0x1d0, // 464;

    // Endpoints services
    FIND_ServerS_REQUEST = 0x1A6, // 422
    FIND_ServerS_RESPONSE = 0x1A9, // 425

    GET_ENDPOINTS_REQUEST  = 0x1ac, // 428
    GET_ENDPOINTS_RESPONSE = 0x1af, // 431

    // Secure channel services
    OPEN_SECURE_CHANNEL_REQUEST  = 0x1be, // 446
    OPEN_SECURE_CHANNEL_RESPONSE = 0x1c1, // 449

    TRANSLATE_BROWSE_PATHS_TO_NODE_IdS_REQUEST  = 0x22A, // 554
    TRANSLATE_BROWSE_PATHS_TO_NODE_IdS_RESPONSE = 0x22D, // 557

    READ_REQUEST  = 0x277, // 631
    READ_RESPONSE = 0x27A, // 634

    WRITE_REQUEST  = 0x2A1, //673
    WRITE_RESPONSE = 0x2A4, // 676


    CALL_REQUEST  = 712, 
    CALL_RESPONSE = 715, // 754

    CREATE_MONITORED_ITEMS_REQUEST  = 0x2EF, // 751
    CREATE_MONITORED_ITEMS_RESPONSE = 0x2F2, // 754

    DELETE_MONITORED_ITEMS_REQUEST  = 0x30d, // 781
    DELETE_MONITORED_ITEMS_RESPONSE = 0x310, // 784

    CREATE_SUBSCRIPTION_REQUEST  = 0x313, //787
    CREATE_SUBSCRIPTION_RESPONSE = 0x316, //790

    DELETE_SUBSCRIPTION_REQUEST  = 0x34f, //847
    DELETE_SUBSCRIPTION_RESPONSE = 0x352, //850

    PUBLISH_REQUEST = 0x33A,  // 826
    PUBLISH_RESPONSE = 0x33D, // 829

    REPUBLISH_REQUEST = 832, 
    REPUBLISH_RESPONSE = 835, 

    SET_PUBLISHING_MODE_REQUEST = 0x31F,  // 799
    SET_PUBLISHING_MODE_RESPONSE = 0x322, // 802

    ADD_NODES_REQUEST = 0x1e8, //488;
    ADD_NODES_RESPONSE = 0x1eb, //491;

    DELETE_NODES_REQUEST = 0x1f4, //500;
    DELETE_NODES_RESPONSE = 0x1f7, //503;

    ADD_REFERENCES_REQUEST  = 0x1ee, //494;
    ADD_REFERENCES_RESPONSE = 0x1f1, //497;

    DELETE_REFERENCES_REQUEST  = 0x1fa, //506;
    DELETE_REFERENCES_RESPONSE = 0x1fd, //509;

    SERVICE_FAULT = 0x18d, //397;
  };

  struct NodeId;

  MessageId GetMessageId(const NodeId& id);

}

#endif // __OPC_UA_BINARY_MESSAGE_IdENTIFIERS
