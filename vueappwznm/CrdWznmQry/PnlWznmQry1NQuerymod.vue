<template>
	<v-card v-if="initdone" class="pa-3 my-3 mx-auto" elevation="4">
		<v-card-title>
			<v-row>
				<v-col cols="4">
					<div>
						<span>{{Cpt}}</span>
					</div>
				</v-col>
				<v-col cols="8" align="end">
					&#160;
					<v-btn
						v-if="statapp.srefIxWznmVExpstate=='regd'"
						fab
						small
						light
						color="primary"
						v-on:click="handleButClipboardClick()"
						:value="1"
					>
						<v-icon color="white">mdi-clipboard</v-icon>
					</v-btn>
					&#160;&#160;
					<v-btn
						v-if="statapp.srefIxWznmVExpstate=='regd'"
						fab
						small
						light
						color="primary"
						v-on:click="handleButClick('ButUpClick')"
						:value="1"
						:disabled="!statshr.ButUpActive"
					>
						<v-icon color="white">mdi-chevron-up-box</v-icon>
					</v-btn>
					&#160;
					<v-btn
						v-if="statapp.srefIxWznmVExpstate=='regd'"
						fab
						small
						light
						color="primary"
						v-on:click="handleButClick('ButDownClick')"
						:value="1"
						:disabled="!statshr.ButDownActive"
					>
						<v-icon color="white">mdi-chevron-down-box</v-icon>
					</v-btn>
					&#160;
					<v-btn
						v-if="statapp.srefIxWznmVExpstate=='regd'"
						fab
						small
						light
						color="primary"
						v-on:click="handleButCrdopenClick('ButViewClick')"
						:value="1"
						:disabled="!statshr.ButViewActive"
					>
						<v-icon color="white">mdi-book-arrow-up</v-icon>
					</v-btn>
					&#160;&#160;
					<v-btn
						v-if="statapp.srefIxWznmVExpstate=='regd'"
						fab
						small
						light
						color="primary"
						v-on:click="handleButCrdopenClick('ButNewClick')"
						:value="1"
					>
						<v-icon color="white">mdi-file-plus</v-icon>
					</v-btn>
					&#160;
					<v-btn
						v-if="statapp.srefIxWznmVExpstate=='regd'"
						fab
						small
						light
						color="primary"
						v-on:click="handleButClick('ButDeleteClick')"
						:value="1"
						:disabled="!statshr.ButDeleteActive"
					>
						<v-icon color="white">mdi-file-remove</v-icon>
					</v-btn>
					&#160;&#160;
					&#160;
					<v-btn
						v-if="statapp.srefIxWznmVExpstate=='regd'"
						fab
						small
						light
						color="primary"
						v-on:click="statapp.srefIxWznmVExpstate='mind'"
						:value="1"
					>
						<v-icon color="white">mdi-minus-circle</v-icon>
					</v-btn>
					&#160;
					<v-btn
						v-if="statapp.srefIxWznmVExpstate=='mind'"
						fab
						small
						light
						color="primary"
						v-on:click="statapp.srefIxWznmVExpstate='regd'"
						:value="1"
					>
						<v-icon color="white">mdi-plus-circle</v-icon>
					</v-btn>
				</v-col>
			</v-row>
		</v-card-title>

		<v-card-text
			v-if="statapp.srefIxWznmVExpstate=='regd'"
		>
			<v-data-table
				:headers="headers"
				:items="contapp.rows"
				:items-per-page="10"
				item-key="jnum"
				single-select
				show-select
				class="elevation-1 my-3"
				v-on:item-selected="handleSelect"
			/>

			<v-row>
				<v-col align="end">
					<v-tooltip left>
						<template v-slot:activator="{on,attrs}">
							<v-btn
								fab
								small
								light
								v-bind="attrs"
								v-on="on"
								:color="fiFCsiQst.sref == 'ong' ? 'orange' : fiFCsiQst.sref == 'red' ? 'red' : fiFCsiQst.sref == 'yel' ? 'yellow' : fiFCsiQst.sref == 'grn' ? 'green' : 'primary'"
								v-on:click="handleButClick('ButRefreshClick')"
							>
								<v-icon color="white">mdi-refresh</v-icon>
							</v-btn>
						</template>
						{{fiFCsiQst.tit1}}
					</v-tooltip>
				</v-col>
			</v-row>
		</v-card-text>
	</v-card>
</template>

<script>
	import Wznm from '../../scripts/Wznm';

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'PnlWznmQry1NQuerymod',

		props: {
			scrJref: String
		},

		mounted() {
			//console.log("PnlWznmQry1NQuerymod.mounted() with scrJref = " + this.scrJref);

			const dpchapp = {
				"DpchAppWznmInit": {
					"scrJref": this.scrJref
				}
			};

			this.$emit('request', {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppInitReply"});
		},

		methods: {
			/*
			<!-- IP cust - INSERT -->
			*/

			handleButClick: function(ctlsref) {
				const dpchapp = {
					"DpchAppWznmQry1NQuerymodDo": {
						"scrJref": this.scrJref,
						"srefIxVDo": ctlsref
					}
				};

				this.$emit("request", {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppDataDoReply"});
			},

			handleButClipboardClick: function() {
				/*
				*/
				Wznm.copyToClipboard(document, this.continf, this.rst, this.statshrqry, this.tag,
							["Ref"],
							["ref"]);
				/*
				*/
			},

				handleButCrdopenClick: function(ctlsref) {
				const dpchapp = {
					"DpchAppWznmQry1NQuerymodDo": {
						"scrJref": this.scrJref,
						"srefIxVDo": ctlsref
					}
				};

				this.$emit("request", {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppDoCrdopenReply"});
			},

			handleSelect: function(obj) {
				var stgiacqry = this.stgiacqry;

				if (!obj.value) stgiacqry.jnum = 0;
				else stgiacqry.jnum = obj.item.jnum;

				const dpchapp = {
					"DpchAppWznmQry1NQuerymodData": {
						"scrJref": this.scrJref,
						"StgIacQryWznmQry1NQuerymod": stgiacqry
					}
				};

				this.$emit("request", {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppDataDoReply"});
			},

			updateEng: function(mask) {
				var dpchapp = {
					"scrJref": this.scrJref
				}

				if (mask.indexOf("contiac") != -1) dpchapp["ContIacWznmQry1NQuerymod"] = this.contiac;

				//console.log(JSON.stringify({"DpchAppWznmQry1NQuerymodData": dpchapp}))

				this.$emit("request", {scrJref: this.scrJref, dpchapp: {"DpchAppWznmQry1NQuerymodData": dpchapp}, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				/*
				<!-- IP mergeDpchEngData - BEGIN -->
				*/
				if (dpcheng.ContInfWznmQry1NQuerymod) this.continf = dpcheng.ContInfWznmQry1NQuerymod;
				if (dpcheng.FeedFCsiQst) this.feedFCsiQst = dpcheng.FeedFCsiQst;
				if (dpcheng.StatAppWznmQry1NQuerymod) this.statapp = dpcheng.StatAppWznmQry1NQuerymod;
				if (dpcheng.StatShrWznmQry1NQuerymod) this.statshr = dpcheng.StatShrWznmQry1NQuerymod;
				if (dpcheng.StgIacWznmQry1NQuerymod) this.stgiac = dpcheng.StgIacWznmQry1NQuerymod;
				if (dpcheng.TagWznmQry1NQuerymod) {
					Wznm.unescapeBlock(dpcheng.TagWznmQry1NQuerymod);
					this.tag = dpcheng.TagWznmQry1NQuerymod;
				}
				if (dpcheng.ListWznmQQry1NQuerymod) this.rst = dpcheng.ListWznmQQry1NQuerymod;
				if (dpcheng.StatAppQryWznmQry1NQuerymod) this.statappqry = dpcheng.StatAppQryWznmQry1NQuerymod;
				if (dpcheng.StatShrQryWznmQry1NQuerymod) this.statshrqry = dpcheng.StatShrQryWznmQry1NQuerymod;
				if (dpcheng.StgIacQryWznmQry1NQuerymod) this.stgiacqry = dpcheng.StgIacQryWznmQry1NQuerymod;
				/*
				<!-- IP mergeDpchEngData - END -->
				*/

				if (dpcheng.TagWznmQry1NQuerymod) {
					var tcos = [];

					/*
					*/
					tcos.push({value: "jnum", text: "jnum"}, {value: "TcoRef", text: this.tag.TcoRef});
					/*
					*/

					this.contapp.tcos = tcos;
				}

				if (dpcheng.ListWznmQQry1NQuerymod) {
					var rows = [];

					for (var i = 0; i < this.rst.length; i++) {
						var rec = this.rst[i];
						/*
						*/
						rows.push({jnum: rec["jnum"], TcoRef: rec["ref"]})
						/*
						*/

					}

					this.contapp.rows = rows;
				}
			},

			handleReply: function(obj) {
				if (obj.then == "handleDpchAppInitReply") this.handleDpchAppInitReply(obj.dpcheng);
				else if (obj.then == "handleDpchAppDataDoReply") this.handleDpchAppDataDoReply(obj.srefIxWznmVDpch, obj.dpcheng);
				else if (obj.then == "handleDpchAppDoCrdopenReply") this.handleDpchAppDoCrdopenReply(obj.srefIxWznmVDpch, obj.dpcheng);
			},

			handleDpchAppInitReply: function(dpcheng) {
				this.mergeDpchEngData(dpcheng);

				this.initdone = true;
			},

			handleDpchAppDataDoReply: function(srefIxWznmVDpch, dpcheng) {
				if (srefIxWznmVDpch == "DpchEngWznmQry1NQuerymodData") this.mergeDpchEngData(dpcheng);
			},

			handleDpchAppDoCrdopenReply: function(srefIxWznmVDpch, dpcheng) {
				if (srefIxWznmVDpch == "DpchEngWznmConfirm")
					if (dpcheng.accepted)
						this.$emit("crdopen", {srefCrd: dpcheng.sref, scrJrefCrd: dpcheng.scrJref, newtabNotInplace: false});
			},

			/*
			*/
			/*
			*/

			handleUpdate: function(obj) {
				/*
				*/
				if (obj.srefIxWznmVDpch == "DpchEngWznmQry1NQuerymodData") this.mergeDpchEngData(obj.dpcheng);
				/*
				*/
			}
		},

		computed: {
			/*
			*/
			/*
			*/
			Cpt: function() {
				if (this.statapp.srefIxWznmVExpstate == "mind") return(this.tag.Cpt + " (" + this.statshrqry.ntot + ")");
				return this.tag.Cpt;
			},
			/*
			*/

			headers: function() {
				return this.contapp.tcos.filter(x => x.value != "jnum")
			},

			fiFCsiQst: function() {
				if (this.feedFCsiQst && this.continf)
					for (var i = 0; i < this.feedFCsiQst.length; i++)
						if (this.feedFCsiQst[i].num == this.continf.numFCsiQst) return this.feedFCsiQst[i];

				return {sref: "gry", tit1: "invalid"}
			}
		},

		data: () => ({
			initdone: false,

			/*
			*/
			continf: null,

			feedFCsiQst: null,

			statapp: null,

			statshr: null,

			stgiac: null,

			tag: null,

			rst: null,

			statappqry: null,

			statshrqry: null,

			stgiacqry: null,

			contapp: {
				tcos: [],
				rows: [],

			},
			/*
			*/
			
			/*
			<!-- IP data.cust - INSERT -->
			*/
		})
	}
</script>
