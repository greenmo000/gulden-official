// Copyright (c) 2011-2015 The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.
//
// File contains modifications by: The Gulden developers
// All modifications:
// Copyright (c) 2016 The Gulden developers
// Authored by: Malcolm MacLeod (mmacleod@webmail.co.za)
// Distributed under the GULDEN software license, see the accompanying
// file COPYING

#ifndef BITCOIN_QT_OPTIONSMODEL_H
#define BITCOIN_QT_OPTIONSMODEL_H

#include "amount.h"
#include "_Gulden/ticker.h"
#include "_Gulden/nockssettings.h"

#include <QAbstractListModel>

QT_BEGIN_NAMESPACE
class QNetworkProxy;
QT_END_NAMESPACE

class OptionsModel;
class QSettings;

class GuldenOptionsModel : public QObject {
    Q_OBJECT

public:
    GuldenOptionsModel(OptionsModel* parent);
    ~GuldenOptionsModel();
    void InitSettings(QSettings& settings);
    void setLocalCurrency(const QString& value);
    QString getLocalCurrency();

private:
    OptionsModel* m_pImpl;
    QString localCurrency;

Q_SIGNALS:
    void localCurrencyChanged(QString currency);
};

/** Interface from Qt to configuration data structure for Bitcoin client.
   To Qt, the options are presented as a list with the different options
   laid out vertically.
   This can be changed to a tree once the settings become sufficiently
   complex.
 */
class OptionsModel : public QAbstractListModel {
    Q_OBJECT

public:
    explicit OptionsModel(QObject* parent = 0, bool resetSettings = false);

    enum OptionID {
        StartAtStartup, // bool
        HideTrayIcon, // bool
        MinimizeToTray, // bool
        MapPortUPnP, // bool
        MinimizeOnClose, // bool
        ProxyUse, // bool
        ProxyIP, // QString
        ProxyPort, // int
        ProxyUseTor, // bool
        ProxyIPTor, // QString
        ProxyPortTor, // int
        DisplayUnit, // BitcoinUnits::Unit
        ThirdPartyTxUrls, // QString
        Language, // QString
        CoinControlFeatures, // bool
        ThreadsScriptVerif, // int
        DatabaseCache, // int
        SpendZeroConfChange, // bool
        Listen, // bool
        OptionIDRowCount,
    };

    void Init(bool resetSettings = false);
    void Reset();

    int rowCount(const QModelIndex& parent = QModelIndex()) const;
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const;
    bool setData(const QModelIndex& index, const QVariant& value, int role = Qt::EditRole);
    /** Updates current unit in memory, settings and emits displayUnitChanged(newUnit) signal */
    void setDisplayUnit(const QVariant& value);

    /* Explicit getters */
    bool getHideTrayIcon() { return fHideTrayIcon; }
    bool getMinimizeToTray() { return fMinimizeToTray; }
    bool getMinimizeOnClose() { return fMinimizeOnClose; }
    int getDisplayUnit() { return nDisplayUnit; }
    QString getThirdPartyTxUrls() { return strThirdPartyTxUrls; }
    bool getProxySettings(QNetworkProxy& proxy) const;
    bool getCoinControlFeatures() { return fCoinControlFeatures; }
    const QString& getOverriddenByCommandLine() { return strOverriddenByCommandLine; }

    /* Restart flag helper */
    void setRestartRequired(bool fRequired);
    bool isRestartRequired();

    GuldenOptionsModel* guldenSettings;
    friend class GuldenOptionsModel;

    void setTicker(CurrencyTicker* ticker)
    {
        currencyTicker = ticker;
    }
    CurrencyTicker* getTicker()
    {
        return currencyTicker;
    }

    void setNocksSettings(NocksSettings* settings)
    {
        nocksSettings = settings;
    }
    NocksSettings* getNocksSettings()
    {
        return nocksSettings;
    }

private:
    /* Qt-only settings */
    bool fHideTrayIcon;
    bool fMinimizeToTray;
    bool fMinimizeOnClose;
    QString language;
    int nDisplayUnit;
    QString strThirdPartyTxUrls;
    bool fCoinControlFeatures;
    /* settings that were overriden by command-line */
    QString strOverriddenByCommandLine;

    CurrencyTicker* currencyTicker;
    NocksSettings* nocksSettings;

    void addOverriddenOption(const std::string& option);

    void checkAndMigrate();
Q_SIGNALS:
    void displayUnitChanged(int unit);
    void coinControlFeaturesChanged(bool);
    void hideTrayIconChanged(bool);
};

#endif // BITCOIN_QT_OPTIONSMODEL_H
